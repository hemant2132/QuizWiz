/*--------------------HEADER FILES--------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define clr() system("cls")

/*--------------------GLOBAL VARIABLES--------------------*/

int wow;

/*--------------------FUNCTION PROTOTYPES--------------------*/

void start();
void signup();
void sign();
int check();
void login();
int srch();
void menu();
void play();
void leaderb();
void profile();
void afans();
void ansa(char a);
void ansb(char a);
void ansc(char a);
void ansd(char a);
void root_set();
void set1();
void rules();
void achieve();
void record();
void info();
void rem(char un[20]);
void update(char un[20]);
void admin();

// delay function
void fordelay(int j)
{
  int i, k;
  for (i = 0; i < j; i++)
    k = i;
}

/*--------------------USER--------------------*/

// user node
struct node
{
  int age;
  char name[20], uname[20], pass[20], title[20], school[20], nat[20];

  int score, zer, ten, twe, thi, fort, fif; //for playing record

  int strk, mxstrk; //for "achievement" section
};

// user node for current user
struct node *ob = NULL;

// user node constructor
void cons()
{
  ob->age = 0;

  strcpy(ob->name, "null");
  strcpy(ob->uname, "null");
  strcpy(ob->pass, "null");
  strcpy(ob->title, "null");
  strcpy(ob->school, "null");
  strcpy(ob->nat, "null");

  ob->score = ob->zer = ob->ten = ob->twe = ob->thi = ob->fort = ob->fif = 0;

  ob->strk = ob->mxstrk = 0;
}

/*--------------------START MENU--------------------*/

// start-menu
void start()
{
  int op, x;
  system("color 09");
  do
  {
    x = 1;
    clr();
    printf("\t\t\t\t\t\xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\       QUIZWIZ        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3\n\n");
    printf("\t\t\t\t\t1.Login\n\t\t\t\t\t2.Signup\n\t\t\t\t\t3.Exit\n\n");
    printf("\t\t\t\t\tEnter option\n\t\t\t\t\t");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      login();
      break;
    case 2:
      signup();
      break;
    case 3:
      exit(0);
    case 4:
      admin();
      break;
    default:
      printf("Wrong input\ntry again"), x = 0;
    }

  } while (!x);
}

// admin - display registered users
void admin()
{
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  FILE *fin = fopen("quiz.dat", "rb");
  while (fread(tmp, sizeof(struct node), 1, fin))
    printf("%s %s\n", tmp->uname, tmp->pass);
  getch();
  start();
}

/*--------------------LOGIN-SIGNUP--------------------*/

// check wheteher the username is taken or not
int check(char u[20])
{
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  FILE *fin = fopen("quiz.dat", "rb");
  fseek(fin, 0, SEEK_SET);
  while (fread(tmp, sizeof(struct node), 1, fin))
  {
    if (strcmp(tmp->uname, u) == 0)
      return 0;
  }

  return 1;
}

// signup page
void sign()
{
  clr();
  system("color F9");
  int op, len, i;
  char ch, p1[20], p2[20];

  printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\  SIGNUP  \xB1\xB1\xB1\xB1\xB1\xB1\n\n");
  printf("1.Name* : %s\n2.Age* : %d\n3.User name* : %s\n", ob->name, ob->age, ob->uname);
  printf("4.Password* : %s\n5.Title : %s\n6.School : %s\n7.Nationality : %s\n",
         ob->pass, ob->title, ob->school, ob->nat);
  printf("8.Submit\n9.Back to Start Menu\n");

  printf("\nNote-fields marked with asterix(*) should be filled mandatorily");
  printf("\n    -username is unique and can't be changed later");
  printf("\n    -password should contain only alphanumerics");
  printf("\n    -age should be above 5 and below 120 to be eligible\n\n");
  printf("Enter option\n");
  scanf("%d", &op);

  switch (op)
  {
  case 1:
    printf("Enter name\n");
    scanf(" %[^\n]s", ob->name);
    getch();
    sign();
    break;
  case 2:
    printf("Enter age\n");
    scanf("%d", &(ob->age));
    if (ob->age <= 5 || ob->age >= 120)
    {
      printf("Age should be above 5 and below 120 to be eligible\n");
      ob->age = 0;
    }
    getch();
    sign();
    break;
  case 3:
    printf("Enter user name\n");
    scanf(" %[^\n]s", ob->uname);
    if (!check(ob->uname))
    {
      printf("User name already exists\n");
      strcpy(ob->uname, "null");
    }
    getch();
    sign();
    break;
  case 4:
    printf("Enter password\n");
    i = 0;
    do
    {
      p1[i] = getch();
      i++;
      if ((p1[i - 1] >= 48 && p1[i - 1] <= 57) || (p1[i - 1] >= 65 && p1[i - 1] <= 90) || (p1[i - 1] >= 97 && p1[i - 1] <= 122))
        printf("*");
    } while ((p1[i - 1] >= 48 && p1[i - 1] <= 57) || (p1[i - 1] >= 65 && p1[i - 1] <= 90) || (p1[i - 1] >= 97 && p1[i - 1] <= 122));
    p1[i - 1] = '\0';

    printf("\nEnter password again for confirmation\n");
    i = 0;
    do
    {
      p2[i] = getch();
      i++;
      if ((p2[i - 1] >= 48 && p2[i - 1] <= 57) || (p2[i - 1] >= 65 && p2[i - 1] <= 90) || (p2[i - 1] >= 97 && p2[i - 1] <= 122))
        printf("*");
    } while ((p2[i - 1] >= 48 && p2[i - 1] <= 57) || (p2[i - 1] >= 65 && p2[i - 1] <= 90) || (p2[i - 1] >= 97 && p2[i - 1] <= 122));
    p2[i - 1] = '\0';

    if (!strcmp(p1, p2))
    {
      len = strlen(p1);
      for (i = 0; i < len; ++i)
      {
        if (!((p1[i] >= 48 && p1[i] <= 57) || (p1[i] >= 65 && p1[i] <= 90) || (p1[i] >= 97 && p1[i] <= 122)))
          break;
      }

      if (i != len)
      {
        printf("password should contain only alphanumerics\n");
        printf("password not created\n");
      }
      else
        strcpy(ob->pass, p1);
    }
    else
      printf("password not created\n");

    getch();
    sign();
    break;
  case 5:
    printf("Enter title\n");
    scanf(" %[^\n]s", ob->title);
    getch();
    sign();
    break;
  case 6:
    printf("Enter school\n");
    scanf(" %[^\n]s", ob->school);
    getch();
    sign();
    break;
  case 7:
    printf("Enter nationality\n");
    scanf(" %[^\n]s", ob->nat);
    getch();
    sign();
    break;
  case 8:
    printf("Are you sure(y/n)?\n");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
      if (strcmp(ob->name, "null") != 0 && ob->age != 0 && strcmp(ob->uname, "null") != 0 && strcmp(ob->pass, "null") != 0)
        wow = 1;
      else
      {
        printf("Please fill all the mandatory fields.\nPress any key to try again.\n");
        getch();
        sign();
      }
    }
    else
    {
      printf("press any key to continue\n");
      getch();
      sign();
    }
    break;
  case 9:
    return;
  default:
    printf("wrong input\npress any key to try again\n");
    getch();
    sign();
  }
}

// signup handler
void signup()
{
  wow = 0;

  ob = (struct node *)malloc(sizeof(struct node));
  cons();

  sign();

  if (wow)
  {
    FILE *out = fopen("quiz.dat", "ab");
    fwrite(ob, sizeof(struct node), 1, out);
    fclose(out);
    printf("\nPROCESSING");
    int i;
    for (i = 0; i <= 5; i++)
    {
      fordelay(100000000);
      printf(".");
    }
    clr();

    printf("\nCongratulations!\nYou have successfully registered.\n");
    getch();
  }

  free(ob);

  start();
}

// find user through the provided username and password
int srch(char u[], char p[])
{
  int f = 0;

  FILE *in = fopen("quiz.dat", "rb");
  fseek(in, 0, SEEK_SET);

  struct node *tmp = (struct node *)malloc(sizeof(struct node));

  while (fread(tmp, sizeof(struct node), 1, in))
  {
    if (!strcmp(u, tmp->uname) && !strcmp(p, tmp->pass))
    {
      ob = (struct node *)malloc(sizeof(struct node));
      ob = tmp;
      {
        f = 1;
        break;
      }
    }
  }

  fclose(in);

  return f;
}

// login handler
void login()
{
  int x, i;
  char s1[20], p[20], ch;
  system("color FD");
  do
  {
    clr();

    ch = 'n';

    printf("\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  LOGIN  \xB1\xB1\xB1\xB1\xB1\xB3\n\n");
    printf("Enter username :\n");
    scanf("%s", s1);
    printf("Enter password : \n");
    i = 0;
    do
    {
      p[i] = getch();
      i++;
      if ((p[i - 1] >= 48 && p[i - 1] <= 57) || (p[i - 1] >= 65 && p[i - 1] <= 90) || (p[i - 1] >= 97 && p[i - 1] <= 122))
        printf("*");
    } while ((p[i - 1] >= 48 && p[i - 1] <= 57) || (p[i - 1] >= 65 && p[i - 1] <= 90) || (p[i - 1] >= 97 && p[i - 1] <= 122));
    p[i - 1] = '\0';

    x = srch(s1, p);

    if (!x)
    {
      printf("\ninvalid credentials\n");
      printf("do you wish to try again?(y/n)\n");
      scanf(" %c", &ch);
    }

    else
    {
      printf("\nLOADING");
      int i;
      for (i = 0; i <= 5; i++)
      {
        fordelay(100000000);
        printf(".");
      }
      menu();
    }

  } while (ch == 'y');

  start();
}

/*--------------------HOMEPAGE--------------------*/

// update user node
void update(char un[20])
{
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  FILE *fin = fopen("quiz.dat", "rb");
  fseek(fin, 0, SEEK_SET);

  int i = 0;
  while (fread(tmp, sizeof(struct node), 1, fin))
  {
    if (strcmp(tmp->uname, un) == 0)
    {
      FILE *fout = fopen("quiz.dat", "rb+");

      fseek(fout, i * sizeof(struct node), SEEK_SET);
      getch();
      fwrite(ob, sizeof(struct node), 1, fout);
      fclose(fout);
      break;
    }
    ++i;
  }

  fclose(fin);
}

// homepage menu
void menu()
{
  clr();

  int op;
  system("color F2");
  printf("\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  HOME  \xB1\xB1\xB1\xB1\xB1\xB3\n\n");
  printf("WELCOME %s!\n\n", ob->name);
  printf("1.Play Quiz\n2.View Leaderboard\n3.Profile\n4.Log Out\n");
  printf("\nEnter option\n");
  scanf("%d", &op);

  switch (op)
  {
  case 1:
    play();
    update(ob->uname);
    getch();
    menu();
  case 2:
    leaderb();
    update(ob->uname);
    getch();
    menu();
  case 3:
    profile();
    update(ob->uname);
    getch();
    menu();
  case 4:
    update(ob->uname);
    free(ob);
    start();
  default:
    printf("wrong input\ntry again\n");
    menu();
  }
}

/*--------------------PLAY QUIZ--------------------*/

// play quiz menu
void play()
{
  clr();
  system("color 0B");
  int op;

  printf("\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  HOME : PLAY-QUIZ  \xB1\xB1\xB1\xB1\xB1\xB3\n\n");
  printf("1.Let's Go\n2.Rules and Regulations\n3.Achievements\n4.Back to Menu\n");
  printf("Enter option\n");
  scanf("%d", &op);

  switch (op)
  {
  case 1:
    root_set();
    break;
  case 2:
    rules();
    break;
  case 3:
    achieve();
    break;
  case 4:
    menu();
    break;
  default:
    printf("wrong input\ntry again\n");
    play();
  }
}

// rules-display
void rules()
{
  clr();
  system("color 07");
  printf("\xB1\ PLAY QUIZ - RULES AND REGULATIONS \xB1\n\n");
  printf("1.Total score for each topic is 50.\n2.Only one option is correct out of the given four.\n");
  printf("3.Just Enter the option which you feel is correct and sincerely follow the given  instructions.\n");
  printf("4.There is no time limit.\n5.As soon as you assign a 'title' or your 'nationality' you can view it/them on   top of your screen while playing.\n");
  printf("6.Players make it to the Leaderboard based on their total score.\n");
  printf("\nBest of Luck!\n\nclick any key to return to 'play' menu\n");
  getch();
  play();
}

// achievements page
void achieve()
{
  clr();
  system("color 07");
  int points = 50 * ob->fif + 40 * ob->fort + 30 * ob->thi + 20 * ob->twe + 10 * ob->ten;

  printf("\xB1\  PLAY QUIZ - ACHIEVEMENTS \xB1\n\n");

  printf("1. Score 100 points overall  ");
  if (points >= 100)
    printf("|UNLOCKED|");
  printf("\n");

  printf("2. Score 500 points overall  ");
  if (points >= 500)
    printf("|UNLOCKED|");
  printf("\n");

  printf("3. Score 1000 points overall  ");
  if (points >= 1000)
    printf("|UNLOCKED|");
  printf("\n");

  printf("4. Achieve 5 perfect scores of 50 ");
  if (ob->fif >= 5)
    printf("|UNLOCKED|");
  printf("\n");

  printf("5. Achieve 10 perfect scores of 50 ");
  if (ob->fif >= 10)
    printf("|UNLOCKED|");
  printf("\n");

  printf("6. Achieve 25 perfect scores of 50 ");
  if (ob->fif >= 25)
    printf("|UNLOCKED|");
  printf("\n");

  printf("7. Consecutive 10 answers correct ");
  if (ob->mxstrk >= 10)
    printf("|UNLOCKED|");
  printf("\n");

  printf("8. Consecutive 20 answers correct ");
  if (ob->mxstrk >= 20)
    printf("|UNLOCKED|");
  printf("\n");

  printf("9. Consecutive 50 answers correct ");
  if (ob->mxstrk >= 50)
    printf("|UNLOCKED|");
  printf("\n");

  printf("10. Play more than 10 games ");
  if (ob->fif + ob->fort + ob->thi + ob->twe + ob->ten + ob->zer >= 10)
    printf("|UNLOCKED|");
  printf("\n");

  printf("\n\nclick any key to return to 'play' menu\n");
  getch();
  play();
}

// quiz - question-set handler
void root_set()
{
  ob->score = 0;
  srand(time(0));
  int x = rand() % 5 + 1;

  switch (x)
  {
  case 1:
    set1();
    break;
  case 2:
    set2();
    break;
  case 3:
    set3();
    break;
  case 4:
    set4();
    break;
  case 5:
    set5();
    break;
  }
}

// quiz - question header
void afans()
{
  getch();
  clr();
  printf("\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  QUIZ  \xB1\xB1\xB1\xB1\xB1\xB3\n\n");
  printf("Name: %s  Age: %d", ob->name, ob->age);
  if (strcmpi(ob->title, "null"))
    printf("  Title: %s ", ob->title);
  if (strcmpi(ob->nat, "null"))
    printf(" Nationality: %s", ob->nat);
  printf(" Score: %d", ob->score);
  printf("\n\n");
}

// quiz - when option 'a' is correct
void ansa(char a)
{
  printf("\n");
  if (a == 'a')
  {
    printf("correct answer");
    ob->score += 10;
    ob->strk++;
    ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
  }
  else if (a == 'b' || 'c' || 'd')
    printf("incorrect answer\ncorrect answer:a"), ob->strk = 0;
  else
    printf("wrong input"), ob->strk = 0;
}

// quiz - when option 'b' is correct
void ansb(char a)
{
  printf("\n");
  if (a == 'b')
  {
    printf("correct answer");
    ob->score += 10;
    ob->strk++;
    ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
  }
  else if (a == 'a' || 'c' || 'd')
    printf("incorrect answer\ncorrect answer:b"), ob->strk = 0;
  else
    printf("wrong input"), ob->strk = 0;
}

// quiz - when option 'c' is correct
void ansc(char a)
{
  printf("\n");
  if (a == 'c')
  {
    printf("correct answer");
    ob->score += 10;
    ob->strk++;
    ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
  }
  else if (a == 'a' || 'b' || 'd')
    printf("incorrect answer\ncorrect answer:c"), ob->strk = 0;
  else
    printf("wrong input"), ob->strk = 0;
}

// quiz - when option 'd' is correct
void ansd(char a)
{
  printf("\n");
  if (a == 'd')
  {
    printf("correct answer");
    ob->score += 10;
    ob->strk++;
    ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
  }
  else if (a == 'a' || 'b' || 'c')
    printf("incorrect answer\ncorrect answer:d"), ob->strk = 0;
  else
    printf("wrong input"), ob->strk = 0;
}

// quiz - give remark on quiz completion
void remark()
{
  printf("Remark:");
  switch (ob->score)
  {
  case 0:
    printf("Work hard - be stronger,swifter and smarter.");
    ob->zer++;
    break;
  case 10:
    printf("Better luck next time,may the force be with you.");
    ob->ten++;
    break;
  case 20:
    printf("Don't give up,you have the potential.");
    ob->twe++;
    break;
  case 30:
    printf("You can scale new heights,just believe.");
    ob->thi++;
    break;
  case 40:
    printf("So near yet so far,you are a good one buddy.");
    ob->fort++;
    break;
  case 50:
    printf("Perfect! We have the genius here.");
    ob->fif++;
    break;
  }
  printf("\n");
}

// quiz - question set 1
void set1()
{
  char a;
  system("color 0E");
  afans();
  printf("Q 1.Which was Cristiano Ronaldo's first professional football team?\n");
  printf("a)Sporting Lisbon\nb)F.C.Porto\nc)Manchester United\nd)Real Madrid\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansa(a);
  afans();
  printf("Q 2.Who defeated Michael Phelps in Rio Olympics 2016 to give his country its first Gold Medal\n");
  printf("a)Joseph Schooling\nb)Brian Roberts\nc)Lu Xei\nd)Carl Roberts\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansa(a);
  afans();
  printf("Q 3.Who is the first lady Prime Minister in the world?\n");
  printf("a)Indira Gandhi\nb)Margaret Thatcher\nc)Sirimavo Bandaranaike\nd)Angelique Fernandez\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansc(a);
  afans();
  printf("Q 4.______ was the first Chief Minister of Delhi\n");
  printf("a)Chaudhary Brahm Prakash\nb)Shiela Dikshit\nc)Madan Lal Khurana\nd)Shushma Swaraj\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansa(a);
  afans();
  printf("Q 5.Which of the following is not in India?\n");
  printf("a)Yanam\nb)Itanagar\nc)Dilli\nd)Lansdowne\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansc(a);
  afans();

  printf("\nTHANK YOU %s for playing our sports quiz.", ob->name);
  printf("\nHope you enjoyed it.\n\nYour Score: %d (out of 50)\n", ob->score);
  remark();

  getch();
}

// quiz - question set 2
void set2()
{
  char a;
  system("color 0E");
  afans();
  printf("Q 1.With which party would you associate Kanshi Ram?\n");
  printf("a)BJP\nb)BSP\nc)Samajwadi Party\nd)Janta Dal(United)\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();
  printf("Q 2.Who won the famous boxing fight - Thrilla in Manila?\n");
  printf("a)Joe Frazier\nb)Muhammad Ali\nc)Mike Tyson\nd)Floyd Mayweather\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();
  printf("Q 3.Which football club won the IFA shield in 1912?\n");
  printf("a)Manchester United\nb)Mohun Bagan\nc)East India F.C.\nd)Nottingham Forest\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();
  printf("Q 4.Which was Steven Smith's first IPL team?\n");
  printf("a)Kochi Tuskers Kerala\nb).Pune Wasrriors India\nc)Rajasthan Royals\nd)Rising Pune Supergiants\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();
  printf("Q 5.This is the biggest scam in the world.\n");
  printf("a)2G scam\nb)Coalgate\nc)Bofors scam\nd)Watergate\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansd(a);
  afans();

  printf("\nTHANK YOU %s for playing our sports quiz.", ob->name);
  printf("\nHope you enjoyed it.\n\nYour Score: %d (out of 50)\n", ob->score);
  remark();

  getch();
}

// quiz - question set 3
void set3()
{
  char a;
  system("color 0E");
  afans();
  printf("Q 1.To what sport will you associate Deepika Pallikal?\n");
  printf("a)Golf\nb)Badminton\nc)Squash\nd)Tennis\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansc(a);
  afans();
  printf("Q 2.Wich country's Prime Minister resigned from his post to spend some family time recently?\n");
  printf("a)Australia\nb)Turkey\nc)New Zealand\nd)Greece\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansc(a);
  afans();
  printf("Q 3.Which of these is an internet browser?\n");
  printf("a)Quora\nb)Line\nc)Wynk\nd)UC\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansd(a);
  afans();
  printf("Q 4.What does the term 'karate' mean?\n");
  printf("a)empty hands\nb)self defence\nc)fighting spirit\nd)peace of mind\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansa(a);
  afans();
  printf("Q 5.Sonia Gandhi is an M.P. from which constituency?\n");
  printf("a)Amethi\nb)Rai Barelli\nc)Kanpur\nd)Allahabad\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();

  printf("\nTHANK YOU %s for playing our sports quiz.", ob->name);
  printf("\nHope you enjoyed it.\n\nYour Score: %d (out of 50)\n", ob->score);
  remark();

  getch();
}

// quiz - question set 4
void set4()
{
  char a;
  system("color 0E");
  afans();
  printf("Q 1.What is the name of the Twitter Bird?\n");
  printf("a)Dorsey Jr.\nb)Tweet Bird\nc)Bluebee\nd)Larry Bird\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansd(a);
  afans();
  printf("Q 2.Who founded the Indian National Congress?\n");
  printf("a)Lala Lajpat Rai\nb)A.O.Hume\nc)Motilal Nehru\nd)Lord Cornwallis\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();
  printf("Q 3.Pick the odd one out.(remember this is a Politics Quiz)?\n");
  printf("a)India\nb)China\nc)Switzerland\nd)Argentina\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();
  printf("Q 4.What does the term 'karate' mean?\n");
  printf("a)empty hands\nb)self defence\nc)fighting spirit\nd)peace of mind\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansa(a);
  afans();
  printf("Q 5.First individual medal for independent India in Olympics was won by _____?\n");
  printf("a)Leander Paes\nb)Mark Andrews\nc)Abhinav Bindra\nd)K.D. Jadhav\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansd(a);
  afans();

  printf("\nTHANK YOU %s for playing our sports quiz.", ob->name);
  printf("\nHope you enjoyed it.\n\nYour Score: %d (out of 50)\n", ob->score);
  remark();

  getch();
}

// quiz - question set 5
void set5()
{
  char a;
  system("color 0E");
  afans();
  printf("Q 1.Who was India's first Deputy Prime Minister?\n");
  printf("a)Morarji Desai\nb)I.K.Gujral\nc)Sardar Vallabhai Patel\nd)Shyama Prasad Mukherjee\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansc(a);
  afans();
  printf("Q 2.What does 'h' stand for in http?\n");
  printf("a)hyper\nb)heirarchical\nc)hypo\nd)hello\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansa(a);
  afans();
  printf("Q 3.Which famous annual cycling event is held in France?\n");
  printf("a)Cyclomania\nb)Around France in 80 days\nc)Francycle\nd)Tour de France\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansd(a);
  afans();
  printf("Q 4.Fill in the blanks.If Kiloo is to Subway Surfers,then ____ is to Temple Run.\n");
  printf("a)Vanilla\nb)Supercell\nc)Imangi\nd)King\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansc(a);
  afans();
  printf("Q 5.Which Indian cricketer partenered V.V.S. Laxman in his magnicient innings of    281 not out?\n");
  printf("a)Md. Kaif\nb)Rahul Dravid\nc)Sachin Tendulkar\nd)M.S. Dhoni\n");
  printf("Enter option\n");
  scanf(" %c", &a);
  ansb(a);
  afans();

  printf("\nTHANK YOU %s for playing our sports quiz.", ob->name);
  printf("\nHope you enjoyed it.\n\nYour Score: %d (out of 50)\n", ob->score);
  remark();

  getch();
}

/*--------------------PROFILE--------------------*/

// deactivate account - remove user node 
void rem(char un[20])
{
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  FILE *fin = fopen("quiz.dat", "rb");
  FILE *fout = fopen("temp.dat", "wb");
  fseek(fin, 0, SEEK_SET);

  while (fread(tmp, sizeof(struct node), 1, fin))
  {
    if (strcmp(tmp->uname, un))
      fwrite(tmp, sizeof(struct node), 1, fout);
  }

  fclose(fin);
  fclose(fout);
  remove("quiz.dat");
  rename("temp.dat", "quiz.dat");
}

// profile menu
void profile()
{
  clr();

  int op;
  char ch;
  system("color 04");
  printf("\t\t\t\t\t    \xB3\xB1\xB1\xB1\xB1\xB1\  HOME - PROFILE  \xB1\xB1\xB1\xB1\xB1\xB3\n");
  printf("\n1.View Playing Record\n2.Player information\n3.Deactivate Account\n4.Back to Menu\n");
  printf("Enter option\n");
  scanf("%d", &op);

  switch (op)
  {
  case 1:
    record();
    getch();
    profile();
    break;
  case 2:
    info();
    getch();
    profile();
    break;
  case 3:
    printf("are you sure?\n");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
      rem(ob->uname);
      printf("account successfully deleted\n");
      free(ob);
      getch();
      start();
    }
    else
    {
      getch();
      profile();
    }
    break;
  case 4:
    menu();
    break;
  default:
    printf("wrong input\ntry again\n");
    getch();
    profile();
  }
}

// playing record display
void record()
{
  clr();

  printf("Overall\n\ngames played - %d\n", ob->fif + ob->fort + ob->thi + ob->twe + ob->ten + ob->zer);
  printf("total score  - %d\n", 50 * ob->fif + 40 * ob->fort + 30 * ob->thi + 20 * ob->twe + 10 * ob->ten);
  printf("\n50s - %d\n40s - %d\n30s - %d\n20s - %d\n10s - %d\n 0s - %d", ob->fif, ob->fort, ob->thi, ob->twe, ob->ten, ob->zer);
  printf("\nclick any key to return to PROFILE page\n");
}

// view and edit profile info
void info()
{
  clr();

  int op;
  char ch;

  printf("PROFILE - PLAYER INFORMATION\n\n");
  printf("Current Information\n1.Name: %s\n2.Age: %d\n3.Password: %s\n4.School: %s\n5.Nationality: %s\n6.Title: %s",
         ob->name, ob->age, ob->pass, ob->school, ob->nat, ob->title);
  printf("\nany changes?(y/n)\n");
  scanf(" %c", &ch);
  if (ch == 'n')
  {
    update(ob->uname);
    profile();
  }
  else if (ch == 'y')
  {
    printf("Enter the field no. to which you want to make changes\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      printf("Enter name\n");
      scanf(" %[^\n]s", ob->name);
      info();
      break;
    case 2:
      printf("Enter age\n");
      scanf("%d", &(ob->age));
      info();
      break;
    case 3:
      printf("Enter password\n");
      scanf(" %[^\n]s", ob->pass);
      info();
      break;
    case 4:
      printf("Enter school\n");
      scanf(" %[^\n]s", ob->school);
      info();
      break;
    case 5:
      printf("Enter nationality\n");
      scanf(" %[^\n]s", ob->nat);
      info();
      break;
    case 6:
      printf("Enter title\n");
      scanf(" %[^\n]s", ob->title);
      info();
      break;
    default:
      printf("wrong input");
      getch();
      info();
    }
  }
  else
  {
    printf("wrong input");
    getch();
    info();
  }
}

/*--------------------LEADERBOARD--------------------*/

struct node1
{
  int age;
  char name[20], uname[20], pass[20], title[20], school[20], nat[20];

  int score, zer, ten, twe, thi, fort, fif; //for playing record

  int strk, mxstrk; //for "achievement" section
  struct node1 *next;
};

struct node1 *current = NULL, *head = NULL;
void create(struct node *p)
{
  printf("%s\n", p->uname);
  struct node1 *n_node = (struct node1 *)malloc(sizeof(struct node1));
  n_node->age = p->age;
  strcpy(n_node->name, p->name);
  strcpy(n_node->uname, p->uname);
  strcpy(n_node->pass, p->pass);
  strcpy(n_node->title, p->title);
  strcpy(n_node->school, p->school);
  strcpy(n_node->nat, p->nat);
  n_node->score = p->score;
  n_node->zer = p->zer;
  n_node->ten = p->ten;
  n_node->twe = p->twe;
  n_node->thi = p->thi;
  n_node->fort = p->fort;
  n_node->fif = p->fif;
  n_node->strk = p->strk;
  n_node->mxstrk = p->mxstrk;
  n_node->next = NULL;
  if (head == NULL)
  {
    head = n_node;
    current = n_node;
  }
  else
  {
    current->next = n_node;
    current = n_node;
  }
}

void sortll(struct node1 *first)
{
  struct node1 *new1 = first;
  struct node1 *count;
  for (; new1->next != NULL; new1 = new1->next)
  {
    for (count = new1->next; count != NULL; count = count->next)
    {
      if (new1->score < count->score)
      {
        int temp = new1->score;
        new1->score = count->score;
        count->score = temp;
        temp = new1->age;
        new1->age = count->age;
        count->age = temp;
        temp = new1->strk;
        new1->strk = count->strk;
        count->strk = temp;
        temp = new1->mxstrk;
        new1->mxstrk = count->mxstrk;
        count->mxstrk = temp;
        temp = new1->zer;
        new1->zer = count->zer;
        count->zer = temp;
        temp = new1->ten;
        new1->ten = count->ten;
        count->ten = temp;
        temp = new1->twe;
        new1->twe = count->twe;
        count->twe = temp;
        temp = new1->thi;
        new1->thi = count->thi;
        count->thi = temp;
        temp = new1->fort;
        new1->fort = count->fort;
        count->fort = temp;
        temp = new1->fif;
        new1->fif = count->fif;
        count->fif = temp;
        char tem[20];
        strcpy(tem, new1->name);
        strcpy(new1->name, count->name);
        strcpy(count->name, tem);
        strcpy(tem, new1->uname);
        strcpy(new1->uname, count->uname);
        strcpy(count->uname, tem);
        strcpy(tem, new1->title);
        strcpy(new1->title, count->title);
        strcpy(count->title, tem);
        strcpy(tem, new1->school);
        strcpy(new1->school, count->school);
        strcpy(count->school, tem);
        strcpy(tem, new1->nat);
        strcpy(new1->nat, count->nat);
        strcpy(count->nat, tem);
        strcpy(tem, new1->pass);
        strcpy(new1->pass, count->pass);
        strcpy(count->pass, tem);
      }
    }
  }
}

void display(struct node1 *first)
{
  clr();
  struct node1 *nw = first;
  int i = 1;
  system("color 0B");
  printf("\t\t\t\t      \xB3\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\   LEADERBOARD   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB3\n\n");
  printf("\t\t\t\tRANK\tNAME\tSCORE\tAGE\tSCHOOL\tNATIONALITY\n");
  printf("\t\t\t\t----\t----\t-----\t---\t------\t-----------\n");
  while (nw)
  {
    printf("\t\t\t\t%d\t%s\t%d\t%d\t%s\t%s\n", i++, nw->name, nw->score, nw->age, nw->school, nw->nat);
    nw = nw->next;
  }
}

void leaderb()
{
  clr();

  FILE *fin = fopen("quiz.dat", "rb");
  fseek(fin, 0, SEEK_SET);
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  while (fread(tmp, sizeof(struct node), 1, fin))
  {
    create(tmp);
  }
  fclose(fin);
  sortll(head);
  display(head);
  head = NULL;
}

/*--------------------MAIN--------------------*/

int main()
{
  start();
  return 0;
}
