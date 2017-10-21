#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//dice roller
int roll_dice(int dice[]);
//counts dice so that you can see the sum of numbers
void dice_count_computation(int dice[], int dice_count[]);
int array_sum_top_row(int dice_count[]);
int score_top_row(int p1_scorecard[], int num1, int num2);
int three_of_kind(int dice_count[], int dice[]);
int four_of_kind(int dice_count[], int dice[]);
int full_house(int dice_count[]);
int small_straight(int dice[]);
int re_rolls(int dice[],int choice_array[], int top_score, int player);
int re_roll_dice(int choice_array[], int dice[]);
int main_re_roll1(int dice[], int choice_array[], int *top_score1);
int main_re_roll2(int dice[], int choice_array[], int *top_score2);
int large_straight(int dice[]);
int yahtzee(int dice[]);
int chance(int dice[]);
void round_in_main1(int p1_scorecard[], int p1_comb_used[], int *top_score1, int *successful, int dice_count[], int dice[]);
void round_in_main2(int p2_scorecard[], int p2_comb_used[], int *top_score2, int *successful, int dice_count[], int dice[]);
void reset_dice_count(int dice_count[]);
void bonus(int *top_score);
void final_score(int *top_score1, int *top_score2, int p1_scorecard[], int p2_scorecard[], int *p1_score, int *p2_score);
void winner(int *p1_score, int *p2_score);
