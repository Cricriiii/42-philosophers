# philosophers

> Dining philosophers in C — threads+mutexes and processes+semaphores. No deadlock, no starvation, death detected in milliseconds.

![demo](.images/1.gif)

---

## Description

**philosophers** is the classic dining philosophers problem implemented in C, in two distinct flavours.

Five philosophers sit at a table. Each needs two forks to eat. Each fork sits between two philosophers. If every philosopher picks up their left fork simultaneously, nobody can eat — deadlock. If one philosopher always eats while another starves — that's starvation. The goal is to solve both, precisely, under strict timing constraints.

- **philo** — one thread per philosopher, forks protected by mutexes
- **philo_bonus** — one process per philosopher, forks modelled as a semaphore pool

---

## Usage

```bash
./philo     number_of_philosophers  time_to_die  time_to_eat  time_to_sleep  [must_eat_count]
./philo_bonus  number_of_philosophers  time_to_die  time_to_eat  time_to_sleep  [must_eat_count]
```

| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Number of philosophers (and forks) |
| `time_to_die` | Time in ms before a philosopher dies if they haven't started eating |
| `time_to_eat` | Time in ms a philosopher spends eating |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `must_eat_count` | *(optional)* Simulation stops when all philosophers have eaten this many times |

---

## Examples

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same, stop after each philosopher eats 7 times
./philo 5 800 200 200 7

# 4 philosophers — should never die
./philo 4 410 200 200

# 1 philosopher — should die (only one fork)
./philo 1 800 200 200
```

---

## Implementations

### philo — threads + mutexes

Each philosopher runs as a **thread**. Each fork is a **mutex**.

To avoid deadlock, odd and even philosophers pick up forks in opposite order.  
A dedicated monitor thread checks timestamps continuously and triggers death if `time_to_die` is exceeded before the philosopher's last meal.


### philo_bonus — processes + semaphores

Each philosopher runs as a **forked process**. Forks are modelled as a single **semaphore** initialised to `N` — a philosopher acquires two units to eat and releases them when done.

Each philosopher process spawns a dedicated watcher thread that monitors its own death condition. A separate semaphore signals the parent when a philosopher dies or the simulation ends.


---

## Key Constraints

- No data races — verified with `valgrind --tool=helgrind` and `fsanitize=thread`
- Death is detected and logged within a tight margin of `time_to_die`
- Timestamps are printed in milliseconds from simulation start
- Log format strictly followed:
```
timestamp_in_ms  X  has taken a fork
timestamp_in_ms  X  is eating
timestamp_in_ms  X  is sleeping
timestamp_in_ms  X  is thinking
timestamp_in_ms  X  died
```

---

## Build

```bash
# Thread version
cd philo && make

# Process version
cd philo_bonus && make
```

---

## Project Structure

```
philo/
├── srcs/         # philosopher lifecycle, monitor, timing, utils
├── includes/
└── Makefile

philo_bonus/
├── srcs/         # forked philosophers, semaphore logic, watcher threads
├── includes/
└── Makefile
```

---

## References

- `man pthread_create`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- `man sem_open`, `sem_wait`, `sem_post`
- `man gettimeofday`, `usleep`
- [The dining philosophers problem — Dijkstra, 1965](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

---

*Built at 42 Paris by [Christophe Gajean](https://github.com/cgajean).*
