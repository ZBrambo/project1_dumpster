# project1_dumpster
This is a college project for my Program Design class. Originally coded back on Janurary 27, 2025.

# Dumpster Rental Cost Calculator

## Overview
This program calculates the rental cost for dumpsters based on dumpster size and rental duration. It provides an easy way to determine costs for different dumpster sizes (10, 20, 30, and 40 yard) and rental periods.

## Author
Zachary Bram

## Features
- Supports four different dumpster sizes (10, 20, 30, and 40 yard)
- Calculates costs based on rental duration (daily and weekly rates)
- Automatically applies the weekly rate when it's more economical than daily rates
- Simple command-line interface

## Pricing Structure
The program uses the following pricing model:

| Dumpster Size | First Day Cost | Additional Day Cost | Weekly Rate |
|---------------|----------------|---------------------|-------------|
| 10 Yard       | $120           | $80                 | $380        |
| 20 Yard       | $150           | $100                | $420        |
| 30 Yard       | $180           | $120                | $520        |
| 40 Yard       | $200           | $140                | $600        |

When calculating costs, the program automatically applies the weekly rate when it's cheaper than the cumulative daily rate.

## Compilation
To compile the program, use:

```bash
gcc -o dumpster_calculator project1_dumpster.c
```

## Usage
Run the compiled program:

```bash
./dumpster_calculator
```

## Input
The program will prompt you for two inputs:

1. Dumpster selection (1-4):
   - 1: 10-yard dumpster
   - 2: 20-yard dumpster
   - 3: 30-yard dumpster
   - 4: 40-yard dumpster

2. Rental duration (number of days)

## Example
```
Please select from four types of dumpsters: 1, 2, 3, and 4
Enter dumpster selection: 2
Enter days: 10
Charge($): 840
```

In this example, the user selected a 20-yard dumpster (option 2) for 10 days. The program calculated the cost as $840, which represents 1 week at the weekly rate ($420) plus the remaining 3 days at the weekly rate (since 3 days at $100/day would exceed the weekly rate).

## Error Handling
The program validates user input and provides error messages for:
- Invalid dumpster selection (not 1-4)
- Invalid number of days (negative value)

## Notes
- The program rounds charges to the nearest whole dollar
- For rental periods longer than a week, the program calculates the most economical combination of weekly and daily rates
