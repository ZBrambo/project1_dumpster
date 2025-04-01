// project1_dumpster.c
// Author: Zachary Bram
// Calculates the rental cost for dumpsters based on user input
#include <stdio.h>
#include <stdlib.h>

// Define the dumpster type
#define DUMPSTER_TYPES 4

// This is the dumpster pricing details
#define DAY1_10_YARD 120
#define DAY1_20_YARD 150
#define DAY1_30_YARD 180
#define DAY1_40_YARD 200

#define DAILY_10_YARD 80
#define DAILY_20_YARD 100
#define DAILY_30_YARD 120
#define DAILY_40_YARD 140

#define WEEK_10_YARD 380
#define WEEK_20_YARD 420
#define WEEK_30_YARD 520
#define WEEK_40_YARD 600

int main()
{
    int dumpster_selection, days;
    double charge = 0;

    // Prompt for dumpster selection
    printf("Please select from four types of dumpsters: 1, 2, 3, and 4\n");
    printf("Enter dumpster selection:");
    if (scanf("%d", &dumpster_selection) != 1 || dumpster_selection < 1 || dumpster_selection > DUMPSTER_TYPES)
    {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;
    }

    // Prompt for number of days
    printf("Enter days:");
    if (scanf("%d", &days) != 1 || days < 0)
    {
        printf("Invalid days.\n");
        return 1;
    }

    // Calculate the total charge based on dumpster type and days
    switch (dumpster_selection)
    {
    case 1: // Case for 10-yard dumpster
        if (days == 1)
        {
            charge = DAY1_10_YARD;
        }
        else
        {
            int weeks = days / 7;
            int remaining_days = days % 7;
            charge = weeks * WEEK_10_YARD;
            if (remaining_days * DAILY_10_YARD > WEEK_10_YARD)
            {
                charge += WEEK_10_YARD;
            }
            else
            {
                charge += remaining_days * DAILY_10_YARD;
            }
        }
        break;

    case 2: // Case for 20-yard dumpster
        if (days == 1)
        {
            charge = DAY1_20_YARD;
        }
        else if (days <= 7)
        {
            charge = DAY1_20_YARD + ((days - 1) * DAILY_20_YARD);
            if (charge > WEEK_20_YARD)
            {
                charge = WEEK_20_YARD; // Cap at weekly rate
            }
        }
        else
        {
            int weeks = days / 7;
            int remainingDays = days % 7;
            charge = weeks * WEEK_20_YARD;
            if (remainingDays * DAILY_20_YARD > WEEK_20_YARD)
            {
                charge += WEEK_20_YARD;
            }
            else
            {
                charge += remainingDays * DAILY_20_YARD;
            }
        }
        break;

    case 3: // Case for 30-yard dumpster
        if (days == 1)
        {
            charge = DAY1_30_YARD;
        }
        else
        {
            int weeks = days / 7;
            int remaining_days = days % 7;
            charge = weeks * WEEK_30_YARD;
            if (remaining_days * DAILY_30_YARD > WEEK_30_YARD)
            {
                charge += WEEK_30_YARD;
            }
            else
            {
                charge += remaining_days * DAILY_30_YARD;
            }
        }
        break;

    case 4: // Case for 40-yard dumpster
        if (days == 1)
        {
            charge = DAY1_40_YARD;
        }
        else
        {
            int weeks = days / 7;
            int remaining_days = days % 7;
            charge = weeks * WEEK_40_YARD;
            if (remaining_days * DAILY_40_YARD > WEEK_40_YARD)
            {
                charge += WEEK_40_YARD;
            }
            else
            {
                charge += remaining_days * DAILY_40_YARD;
            }
        }
        break;

    default:
        printf("Invalid selection.\n");
        return 1;
    }

    // Print the calculated charge
    printf("Charge($):%.0f\n", charge);
    return 0;
}