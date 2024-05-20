#include <cstdio>

#define NUM_ITEM_PROPS 4

void prompt(void);

// DEVNOTE:
// Did not wanted to complicate the code with input-validation, we are assuming that the
// user will input valid data.
int main ()
{
	int res = 0;
	bool sw = true;
	do {
		prompt();
		printf("do you want to start over again with a new list? 0: NO: 1: YES:");
		scanf("%d", &res);
		if (!res) {
			sw = false;
		}
	} while (sw);
	return 0;
}

static void prompt_num_items (size_t *num_items)
{
	printf("input the number of items: ");
	scanf("%zu", num_items);
}

static void prompt_dat (double *quantity, double *unit_value, double *discount_percentage)
{
	double *q = quantity;
	double *uv = unit_value;
	double *dp = discount_percentage;
	printf("input the quantity, the unit value, and the discount percentage: ");
	scanf("%lf %lf %lf", q, uv, dp);
}

static void prompt_items (size_t const num_items, double items[][NUM_ITEM_PROPS])
{
	for (size_t i = 0; i != num_items; ++i) {
		double *item = &items[i][0];
		double *quantity = &item[0];
		double *unit_value = &item[1];
		double *discount_percentage = &item[2];
		prompt_dat(quantity, unit_value, discount_percentage);
		printf("%lf %lf %lf\n", *quantity, *unit_value, *discount_percentage);
	}
}

static double calc_item_profit (double const *q, double const *uv, double const *dp)
{
	double const quantity = *q;
	double const unit_value = *uv;
	double const discount_percentage = *dp;
	double const discount = (0.01 * discount_percentage);
	// DEVNOTE: here we are assuming that the discount percentage is defined with
	// respect to the unit value of the item; thus, if the item has a 20% discount
	// the customer has to pay 80% of the item unit-value.
	double const profit = quantity * (unit_value * (1.0 - discount));
	return profit;
}

static void set_items_profit(size_t const num_items, double items[][NUM_ITEM_PROPS])
{
	for (size_t i = 0; i != num_items; ++i) {
		double *item = &items[i][0];
		double const *quantity = &item[0];
		double const *unit_value = &item[1];
		double const *discount_percentage = &item[2];
		double *profit = &item[NUM_ITEM_PROPS - 1];
		*profit = calc_item_profit(quantity, unit_value, discount_percentage);
	}
}

static void report_items (size_t const num_items, double const items[][NUM_ITEM_PROPS])
{
	double total_profit = 0;
	double q = 0, uv = 0, dp = 0, p = 0;
	printf("        quantity       unit value       discount %%           profit\n");
	for (size_t i = 0; i != num_items; ++i) {
		double const *item = &items[i][0];
		double const quantity = q = item[0];
		double const unit_value = uv = item[1];
		double const discount_percentage = dp = item[2];
		double const profit = p = item[3];
		total_profit += profit;
		printf("%16.0lf %16.2lf %16.2lf %16.2lf\n", q, uv, dp, p);
	}
	// DEVNOTE: reporting this because it might be of interest to the employee
	printf("TOTAL PROFIT: %lf\n", total_profit);
}

void prompt (void)
{
	size_t num_items = 0;
	prompt_num_items(&num_items);
	double items[num_items][4];
	prompt_items(num_items, items);
	set_items_profit(num_items, items);
	report_items(num_items, items);
}

/*

PurchaseOrder					May 16, 2024

source: src/employee/employee.cpp
author: @misael-diaz

Copyright (C) 2024 Misael Díaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

References:
[0] https://en.cppreference.com/w/cpp

*/
