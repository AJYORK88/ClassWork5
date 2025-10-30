#include <stdio.h>

int main(void) {
    int n, i;
    double units, bill, total = 0.0;
    double highest = -1.0, lowest = 1e9, avg;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        printf("\nEnter units consumed by customer %d: ", i);
        scanf("%lf", &units);
  
        if (units <= 100)
            bill = units * 0.50;
        else if (units <= 300)
            bill = 100 * 0.50 + (units - 100) * 0.75;
        else if (units <= 600)
	    bill = 100 * 0.50 + 200 * 0.75 + (units - 300) * 1.20;
        else
	    bill = 100 * 0.50 + 200 * 0.75 + 300 * 1.20 + (units - 600) * 1.50;

        bill += 20.0;
        if (bill > 500.0)
            bill *= 1.10;

        printf("Total bill for customer %d: $%.2f\n", i, bill);

        total += bill;
        if (bill > highest) highest = bill;
        if (bill < lowest)  lowest  = bill;
    }

    avg = total / n;

    printf("\n--- Billing Summary ---\n");
    printf("Average Bill: $%.2f\n", avg);
    printf("Highest Bill: $%.2f\n", highest);
    printf("Lowest Bill:  $%.2f\n", lowest);
    return 0;
}
