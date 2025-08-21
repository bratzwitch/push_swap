# Push Swap

A sorting algorithm project that sorts data on a stack using a limited set of operations and aims to minimize the number of actions.

## Description

Push Swap is a project about sorting algorithms and their complexity. You have two stacks (A and B) and a set of operations to manipulate them. The goal is to sort stack A in ascending order using the minimum number of operations possible.

## Features

- Efficient sorting algorithms implementation
- Handles various input sizes optimally
- Minimizes the number of operations
- Error handling for invalid inputs
- Comprehensive testing suite

## Available Operations

- `sa`: Swap first 2 elements of stack A
- `sb`: Swap first 2 elements of stack B
- `ss`: Execute `sa` and `sb` simultaneously
- `pa`: Push first element from B to A
- `pb`: Push first element from A to B
- `ra`: Rotate stack A (first element becomes last)
- `rb`: Rotate stack B (first element becomes last)
- `rr`: Execute `ra` and `rb` simultaneously
- `rra`: Reverse rotate stack A (last element becomes first)
- `rrb`: Reverse rotate stack B (last element becomes first)
- `rrr`: Execute `rra` and `rrb` simultaneously

## Compilation

```bash
make
```

This creates the `push_swap` executable.

## Usage

1. Clone the repository:
```bash
git clone https://github.com/bratzwitch/push_swap.git
cd push_swap
```

2. Compile the program:
```bash
make
```

3. Run with numbers to sort:
```bash
./push_swap 4 67 3 87 23
```

## Example

```bash
# Sort 5 random numbers
./push_swap 2 1 3 6 5 8 5
```

Output will be a series of operations:
```
pb
pb
sa
pa
pa
```

## Algorithm Complexity

- **3 numbers**: Maximum 3 operations
- **5 numbers**: Maximum 12 operations  
- **100 numbers**: 
  - 5 points: < 700 operations
  - 4 points: < 900 operations
  - 3 points: < 1100 operations
  - 2 points: < 1300 operations
  - 1 point: < 1500 operations
- **500 numbers**:
  - 5 points: < 5500 operations
  - 4 points: < 7000 operations
  - 3 points: < 8500 operations
  - 2 points: < 10000 operations
  - 1 point: < 11500 operations

## Testing

Use the checker program (if provided) to validate your solution:
```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

Generate random numbers for testing:
```bash
ARG=$(seq 1 100 | sort -R | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## Error Handling

The program handles various error cases:
- Non-integer arguments
- Integers bigger than MAX_INT or smaller than MIN_INT
- Duplicate numbers
- Empty input

## Files Structure

- `push_swap.c`: Main program
- `operations/`: Directory containing all operation functions
- `utils/`: Helper functions
- `push_swap.h`: Header file
- `Makefile`: Compilation rules

## Algorithm Strategy

1. **Small stacks (≤ 3)**: Hardcoded optimal solutions
2. **Medium stacks (4-5)**: Optimized specific algorithms
3. **Large stacks (100+)**: Advanced algorithms like:
   - Radix sort
   - Quick sort adaptation
   - Merge sort approach

## Requirements

- GCC compiler
- Make
- Standard C library

## Author

Viacheslav Moroz - 42 Student
