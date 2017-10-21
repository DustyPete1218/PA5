#include "Yahtzee.h"

int main(void)

{
	srand((unsigned int)time(NULL));

	int dice[6] = { 0 }, p1_scorecard[13] = { 0 }, 
		p1_comb_used[13] = { 0 }, dice_count[7] = { 0 }, index = 0, option = 0,
		top_score1 = 0, menu_option = 0, re_roll = 0, number_of_re_roll = 0, 
		choice_array[5] = { 0 }, successful = 0, round_number = 0, p2_comb_used[13] = {0},
		p2_scorecard[13] = { 0 }, top_score2 = 0, p1_score = 0, p2_score = 0;

	printf("1. Print game rules\n2. Play Yahtzee!\n3. Exit\n");
	scanf("%d", &menu_option);
	system("cls");
	
	//Prints the menu options
	switch (menu_option)
	{
	case 1: printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\nA total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\nThe upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\nIf a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\nOnce a player has chosen to score a box, it may not be changed\nand the combination is no longer in play for future rounds.\nIf the sum of the scores in the upper section is greater than or equal to 63,\nthen 35 more points are added to the players overall score as a bonus.\nThe lower section contains a number of poker like combinations.\n");
		printf("\nThree-of-a-kind----Three dice with the same face----Sum of all face values on the 5 dice\nFour - of - a - kind----Four dice with the same face----Sum of all face values on the 5 dice\nFull house----One pair and a three - of - a - kind----25\nSmall straight----A sequence of four dice----30\nLarge straight----A sequence of five dice----40\nYahtzee(think five - of - a - kind)----Five dice with the same face----50\nChance----May be used for any sequence of dice;this is the catch all combination----Sum of all face values on the 5 dice\n");
		printf("\nWould you still like to play or exit?\n \nPress 2 to play and 3 to exit.\n");
		scanf("%d", &menu_option);
		system("cls");
		break;
	}

	//Different switch statement incase you choose to see the rules before playing the game
	do {
		switch (menu_option) {
		case 2:
			printf("Player 1!\n \n");
			printf("Top score: %d\n \n", top_score1);
			//roll_dice(dice); 

		
			//shows the dice on screen
			printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);
			//re-rolling - i had a bad bug and spent way too much time trying to make it to wear you could only go three times or stopping after 1 or 2 re-rolls
			for (number_of_re_roll = 0; number_of_re_roll < 3; number_of_re_roll++) {
				
				re_roll = main_re_roll1(dice, choice_array, &top_score1);
				if (re_roll == 2) {
					number_of_re_roll = 4;
				}
			}
			number_of_re_roll = 0;
			dice_count_computation(dice, dice_count);
			//select a score/combination
			round_in_main1(p1_scorecard, p1_comb_used, &top_score1, &successful, dice_count, dice);// this function along with the player two function would've made main wayyyy too long so i just put it into a function with some pointers
			successful = 0;
			reset_dice_count(dice_count);// resets dice_count so that it doesnt get int the way of the next players turn
			
		    system("cls");
			printf("Player 2!\n \n");
			printf("Top score: %d\n \n", top_score2);
			roll_dice(dice);
			printf("Die 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);
			
			for (number_of_re_roll = 0; number_of_re_roll < 3; number_of_re_roll++) {
				
				re_roll = main_re_roll2(dice, choice_array, &top_score2);
				if (re_roll == 2) {
					number_of_re_roll = 4;
				}
			}
			number_of_re_roll = 0;
			dice_count_computation(dice, dice_count);
			round_in_main2(p2_scorecard, p2_comb_used, &top_score2, &successful, dice_count, dice);
			successful = 0;
			reset_dice_count(dice_count);

			round_number++;

		}
	} while (round_number < 13);
	//all of the things that happen after all the rounds are over
	bonus(&top_score1);
	bonus(&top_score2);
	final_score(&top_score1, &top_score2, p1_scorecard, p2_scorecard, &p1_score, &p2_score);
	system("cls");
	winner(&p1_score, &p2_score);
	printf("%d", p1_score);
	return 0;

}