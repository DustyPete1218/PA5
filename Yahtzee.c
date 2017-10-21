#include "Yahtzee.h"
/*Pre Req: goes through the dice array and assigns a rolled die to a spot in the array
  Pos Req: Array has all the 5 dice rolls inside*/
int roll_dice(int dice[]){
	int index = 1;
	for (index = 1; index < 6; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}


}
/*Pre Req: goes through and makes a parallel array for the dice[] array and counts things such as how many 5's there are
  Post Req: has counted and shown how many different addition there are for a sum array*/
void dice_count_computation(int dice[], int dice_count[])
{
	int index = 1;

	for (; index < 6; ++index)
	{
		dice_count[dice[index]]++;
	}
}

int array_sum_top_row(int dice_count[])
{
	int sum = 0, index = 0;
	for (index = 0; index > 7; index++)
	{
		sum = sum + dice_count[index];
	}
	return sum;
}

int score_top_row(int p1_scorecard[], int num1, int num)
{
	int score = 0;
	score = p1_scorecard[num1] * num;

	return score;
}

int three_of_kind(int dice_count[], int dice[])
{
	int i = 0, tok = 0, index = 0;
	for (i = 0; i < 7; i++)
	{
		if (dice_count[i] == 3)
		{
			for (index = 1; index <= 5; index++)
			{
				tok += dice[index];
			}
		}

	}
	return tok;
}

int four_of_kind(int dice_count[], int dice[])
{
	int i = 0, tok = 0, index = 0;
	for (i = 0; i < 7; i++)
	{
		if (dice_count[i] == 4)
		{
			for (index = 1; index <= 5; index++)
			{
				tok += dice[index];
			}
		}

	}
	return tok;
	
}

int full_house(int dice_count[])
{
	int i = 0, fh = 0, index = 0;
	for (i = 0; i < 7; i++)
	{
		if (dice_count[i] == 3)
		{
			for (index = 0; index < 7; index++)
			{
				if (dice_count[index] == 2)
				{
					fh = 25;
				}
			}
		}
	}
	return fh;
}

int small_straight(int dice[])
{
	int ss = 0, i = 2, small_straight1 = 0, sequence = 0;
	
	small_straight1 = dice[1];
	for (i = 2; i < 7; i++)
	{
		if ((dice[i] > small_straight1) && (dice[i] < (2 + small_straight1)))
		{
			sequence++;
			small_straight1 = dice[i];
		}
	}
	if (sequence == 3) {
		ss = 30;
	}
	
	return ss;
}

int re_rolls(int dice[], int choice_array[], int top_score, int player)
{
	char t;
	int i = 0;
	printf("\nWhat dice do you want to Re-roll? Press enter when done\n");
	do {
		scanf("%d%c", &choice_array[i], &t);
			i++;
	
	} while (t!= '\n');

	re_roll_dice(choice_array, dice);
	system("cls");
	if (player == 1) {
		printf("Player 1!\n \n");
		player = 0;
	}
	if (player == 2) {
		printf("Player 2!\n \n");
		player = 0;
	}
	printf("Top score: %d\n \n", top_score);
	printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);


	return 0;
}

int re_roll_dice(int choice_array[], int dice[])
{
	int i = 0, new_die = 0;
	for (i = 0; i < 5; ++i) {
		new_die = choice_array[i];
		if (new_die != 0) {
			dice[new_die] = rand() % 6 + 1;
		}
	

	}
	choice_array[0] = 0;
	choice_array[1] = 0;
	choice_array[2] = 0;
	choice_array[3] = 0;
	choice_array[4] = 0;
	return 0;
}

int main_re_roll1(int dice[], int choice_array[], int * top_score1)
{
	

	int re_roll = 0;
	
	printf("\nDo you want to Re-roll any dice?\n1. Yes\n2. No\n");
	if (re_roll == 0) 
	{
		scanf("%d", &re_roll);
	}

	system("cls");
	printf("Player 1!\n \n");
	printf("Top score: %d\n \n", *top_score1);
	printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);

		if (re_roll == 1)
		{
			re_rolls(dice, choice_array, *top_score1, 1);


		}

	
	return re_roll;
}

int main_re_roll2(int dice[], int choice_array[], int *top_score2)
{


	int re_roll = 0;

	printf("\nDo you want to Re-roll any dice?\n1. Yes\n2. No\n");
	if (re_roll == 0)
	{
		scanf("%d", &re_roll);
	}

	system("cls");
	printf("Player 2!\n \n");
	printf("Top score: %d\n \n", *top_score2);

	printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);

	if (re_roll == 1)
	{
		re_rolls(dice, choice_array, *top_score2, 2);


	}


	return re_roll;
}

int large_straight(int dice[])
{
	int ls = 0, i = 2, large_straight1 = 0, sequence = 0;

	large_straight1 = dice[1];
	for (i = 2; i < 7; i++)
	{
		if ((dice[i] > large_straight1) && (dice[i] < (2 + large_straight1)))
		{
			sequence++;
			large_straight1 = dice[i];
		}
	}
	if (sequence == 4) {
		ls = 40;
	}
	printf("%d", ls);
	return ls;
	
}

int yahtzee(int dice[])
{
	int y = 0, index = 1, i = 1, large_straight = 0, number_in_a_row = 0;
	large_straight = dice[1];
	for (i = 1; i < 7; i++)
	{
		if (dice[i] == large_straight)
		{
			number_in_a_row++;
		}

		if (number_in_a_row == 5) 
		{
			y = 50;
		}
	}

	return y;
}

int chance(int dice[])
{
	int chance1 = 0, i = 1;
	for (i = 1; i < 6; i++)
	{
		chance1 += dice[i];
	}
	return chance1;
}

void round_in_main1(int p1_scorecard[], int p1_comb_used[], int * top_score1, int * successful, int dice_count[], int dice[])

{
	int option = 0;
	do {// do loop is to make sure that the user doesn't enter the same option in twice
		printf("\n1. Sum of 1's	7. Three-of-a-kind\n2. Sum of 2's	8. Four-of-a-kind\n3. Sum of 3's	9. Full house\n4. Sum of 4's	10. Small straight\n5. Sum of 5's	11. Large straight\n6. Sum of 6's	12. Yahtzee!!!\n	13. Chance\n \nEnter a combination you want to use: ");
		scanf("%d", &option);
		switch (option)// all of the ways to score
		{

		case 1:
			
			if (p1_comb_used[0] == 1) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);

				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[0] < 1) {
				
				p1_scorecard[0] = score_top_row(p1_scorecard, 0, 1);
				*top_score1 = p1_scorecard[0] + *top_score1;
				p1_comb_used[0] = option;
				successful = 1;
				system("cls");
			}
			break;

		case 2: p1_scorecard[1] = dice_count[2];
			if (p1_comb_used[1] == 2) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[1] < 2) {
				
				p1_scorecard[1] = score_top_row(p1_scorecard, 1, 2);
				*top_score1 = p1_scorecard[1] + *top_score1;
				p1_comb_used[1] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 3: p1_scorecard[2] = dice_count[3];
			if (p1_comb_used[2] == 3) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[2] < 3) {
				
				p1_scorecard[2] = score_top_row(p1_scorecard, 2, 3);
				*top_score1 = p1_scorecard[2] + *top_score1;
				p1_comb_used[2] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 4: p1_scorecard[3] = dice_count[4];
			if (p1_comb_used[3] == 4) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[3] < 4) {
				
				p1_scorecard[3] = score_top_row(p1_scorecard, 3, 4);
				*top_score1 = p1_scorecard[3] + *top_score1;
				p1_comb_used[3] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 5: p1_scorecard[4] = dice_count[5];
			if (p1_comb_used[4] == 5) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[4] < 5) {
				
				p1_scorecard[4] = score_top_row(p1_scorecard, 4, 5);
				*top_score1 = p1_scorecard[4] + *top_score1;
				p1_comb_used[4] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 6: p1_scorecard[5] = dice_count[6];
			if (p1_comb_used[5] == 6) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[5] < 6) {
				
				p1_scorecard[5] = score_top_row(p1_scorecard, 5, 6);
				*top_score1 = p1_scorecard[5] + *top_score1;
				p1_comb_used[5] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 7: p1_scorecard[6] = three_of_kind(dice_count, dice);
			if (p1_comb_used[6] == 7) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[6] < 7) {
				p1_comb_used[6] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 8: p1_scorecard[7] = four_of_kind(dice_count, dice);
			if (p1_comb_used[7] == 8) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[7] < 8) {
				p1_comb_used[7] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 9: p1_scorecard[8] = full_house(dice_count);
			if (p1_comb_used[8] == 9) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[8] < 9) {
				p1_comb_used[8] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 10: p1_scorecard[9] = small_straight(dice);
			if (p1_comb_used[9] == 10) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[9] < 10) {
				p1_comb_used[9] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 11: p1_scorecard[10] = large_straight(dice);
			if (p1_comb_used[10] == 11) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[10] < 11) {
				p1_comb_used[10] = option;
				successful = 1;
				system("cls");
			}
			printf("%d", p1_scorecard[10]);
			break;

		case 12: p1_scorecard[11] = yahtzee(dice);
			if (p1_comb_used[11] == 12) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[11] < 12) {
				p1_comb_used[11] = option;
				successful = 1;
				system("cls");
			}
			printf("%d", p1_scorecard[11]);
			break;

		case 13: p1_scorecard[12] = chance(dice);

			if (p1_comb_used[12] == 13) {
				system("cls");
				printf("Player 1!\n \n");
				printf("Top score: %d\n \n", *top_score1);
				printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n \n", dice[1], dice[2], dice[3], dice[4], dice[5]);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p1_comb_used[12] < 13) {
				p1_comb_used[12] = option;
				successful = 1;
				system("cls");
			}
			printf("%d", p1_scorecard[12]);
			break;

		}
	} while (successful != 1);
	return 0;
}

void round_in_main2(int p2_scorecard[], int p2_comb_used[], int * top_score2, int * successful, int dice_count[], int dice[])
{
	int option = 0;
	do {// do loop is to make sure that the user doesn't enter the same option in twice
		printf("\n1. Sum of 1's	7. Three-of-a-kind\n2. Sum of 2's	8. Four-of-a-kind\n3. Sum of 3's	9. Full house\n4. Sum of 4's	10. Small straight\n5. Sum of 5's	11. Large straight\n6. Sum of 6's	12. Yahtzee!!!\n	13. Chance\n \nEnter a combination you want to use: ");
		scanf("%d", &option);
		switch (option)// all of the ways to score
		{

		case 1:
			if (p2_comb_used[0] == 1) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[0] < 1) {
				p2_scorecard[0] = dice_count[1];
				
				p2_scorecard[0] = score_top_row(p2_scorecard, 0, 1);
				*top_score2 = p2_scorecard[0] + *top_score2;
				p2_comb_used[0] = option;
				successful = 1;
				system("cls");
			}
			break;

		case 2: p2_scorecard[1] = dice_count[2];
			if (p2_comb_used[1] == 2) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[1] < 2) {
				
				p2_scorecard[1] = score_top_row(p2_scorecard, 1, 2);
				*top_score2 = p2_scorecard[1] + *top_score2;
				p2_comb_used[1] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 3: p2_scorecard[2] = dice_count[3];
			if (p2_comb_used[2] == 3) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");;
				break;
			}

			if (p2_comb_used[2] < 3) {
				
				p2_scorecard[2] = score_top_row(p2_scorecard, 2, 3);
				*top_score2 = p2_scorecard[2] + *top_score2;
				p2_comb_used[2] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 4: p2_scorecard[3] = dice_count[4];
			if (p2_comb_used[3] == 4) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[3] < 4) {
				
				p2_scorecard[3] = score_top_row(p2_scorecard, 3, 4);
				*top_score2 = p2_scorecard[3] + *top_score2;
				p2_comb_used[3] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 5: p2_scorecard[4] = dice_count[5];
			if (p2_comb_used[4] == 5) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[4] < 5) {
				
				p2_scorecard[4] = score_top_row(p2_scorecard, 4, 5);
				*top_score2 = p2_scorecard[4] + *top_score2;
				p2_comb_used[4] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 6: p2_scorecard[5] = dice_count[6];
			if (p2_comb_used[5] == 6) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[5] < 6) {
				
				p2_scorecard[5] = score_top_row(p2_scorecard, 5, 6);
				*top_score2 = p2_scorecard[5] + *top_score2;
				p2_comb_used[5] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 7: p2_scorecard[6] = three_of_kind(dice_count, dice);
			if (p2_comb_used[6] == 7) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[6] < 7) {
				p2_comb_used[6] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 8: p2_scorecard[7] = four_of_kind(dice_count, dice);
			if (p2_comb_used[7] == 8) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[7] < 8) {
				p2_comb_used[7] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 9: p2_scorecard[8] = full_house(dice_count);
			if (p2_comb_used[8] == 9) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[8] < 9) {
				p2_comb_used[8] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 10: p2_scorecard[9] = small_straight(dice);
			if (p2_comb_used[9] == 10) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[9] < 10) {
				p2_comb_used[9] = option;
				successful = 1;
				system("cls");
			}

			break;

		case 11: p2_scorecard[10] = large_straight(dice);
			if (p2_comb_used[10] == 11) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[10] < 11) {
				p2_comb_used[10] = option;
				successful = 1;
				system("cls");
			}
			printf("%d", p2_scorecard[10]);
			break;

		case 12: p2_scorecard[11] = yahtzee(dice);
			if (p2_comb_used[11] == 12) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[11] < 12) {
				p2_comb_used[11] = option;
				successful = 1;

				system("cls");
			}
			printf("%d", p2_scorecard[11]);
			break;

		case 13: p2_scorecard[12] = chance(dice);

			if (p2_comb_used[12] == 13) {
				system("cls");
				printf("Player 2!\n \n");
				printf("Top score: %d\n \n", *top_score2);
				printf("You can't do the same thing twice silly!\n");
				break;
			}

			if (p2_comb_used[12] < 13) {
				p2_comb_used[12] = option;
				successful = 1;
				system("cls");
			}
			printf("%d", p2_scorecard[12]);
			break;

		}
	} while (successful != 1);
	return 0;
}

void reset_dice_count(int dice_count[])
{
	dice_count[1] = 0; dice_count[2] = 0; dice_count[3] = 0; dice_count[4] = 0; dice_count[5] = 0; dice_count[6] = 0;
	return 0;
}

void bonus(int *top_score)
{
	
	if (*top_score >= 63)
	{
		*top_score += 35;
	}
}

void final_score(int * top_score1, int * top_score2, int p1_scorecard[], int p2_scorecard[], int *p1_score, int *p2_score)
{

	int i = 0, index = 0;
	for (i = 0; i < 13; i++)
	{
		*p1_score += p1_scorecard[i];
	}
	
	for (index = 0; i < 13; index++)
	{
		*p2_score += p2_scorecard[i];
	}

	*p1_score += *top_score1;
	*p2_score += *top_score2;
}

void winner(int *p1_score, int *p2_score)
{
	if (*p1_score > *p2_score) {
		printf("Player 1's score was %d: \nPlayer 2's score was: %d \nPlayer 1 is the winner!!!\nTry harder next time Player 2.\n", *p1_score, *p2_score);
	}

	if (*p2_score > *p1_score) {
		printf("Player 1's score was %d: \nPlayer 2's score was: %d \nPlayer 2 is the winner!!!\nTry harder next time Player 1.\n", *p1_score, *p2_score);
	}

	if (*p2_score == *p1_score) {
		printf("Player 1's score was %d: \nPlayer 2's score was: %d \nYou both tied! What is wrong with both of you?\n", *p1_score, *p2_score);
	}
	
}
