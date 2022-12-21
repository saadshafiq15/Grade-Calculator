/************************shafiqSaadA1.c**************
Student Name: Saad Shafiq Email Id: sshafi03@uoguelph.ca

Due Date: Friday, October 7 2022  Course Name: CIS 1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/
/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall

compiling:
gcc -std=c99 -Wall shafiqSaadA1.c

Running: ./a.out

OR

gcc -std=c99 -Wall shafiqSaadA1.c -o a1

Running the Program: ./a1
*********************************************************/

#include<stdio.h>

int main(){

    // Declaring variables that should not reset and welcome statement
    int studentNum;
    double avgMark, totalMarks;
    char userResponse = 'y';
    printf("Welcome to ALT1300 admin page\n\n");

    // While loop to check if user wants to continue onto to next student
    while (userResponse == 'y'){
        // Declaring variables 
        double labMark1, labMark2, labMark3, labMark4, labMark5;
        double finalLabMark;
        double a1Mark, a2Mark, a3Mark, finalAMark;
        int mossA1, mossA2, mossA3;
        double quizMark1, quizMark2, quizMark3, quizMark4, finalQuizMark;
        double labExamMark, finalLabExamMark;
        double examWeight, examMark, finalExamMark1, finalExamMark2;
        int overallExamWeight;
        char surveyResp;
        double finalQuizExamMark;
        double overallCourseMark;

        //Student #
        studentNum++;
        printf("Student# %d:\n\n", studentNum);

        //Calculating and displaying lab marks
        printf("Enter 5 lab marks, each separated by a space: ");
        scanf("%lf %lf %lf %lf %lf", &labMark1, &labMark2, &labMark3, &labMark4, &labMark5);
        finalLabMark = (((labMark1 + labMark2 + labMark3 + labMark4 + labMark5) / 5) * 0.2);  
        printf("Overall lab grade (20) = %.2lf / 20\n\n", finalLabMark);
        
        //Calculating and displaying assignment marks with moss check
        printf("Enter 3 assignment marks, each separated by a space: ");
        scanf("%lf %lf %lf", &a1Mark, &a2Mark, &a3Mark);
        printf("Enter MOSS result for A1: ");
        scanf("%d", &mossA1);
        if (mossA1 == 0){
            a1Mark = 0;
        }
        printf("Enter MOSS result for A2: ");
        scanf("%d", &mossA2);
        if (mossA2 == 0){
            a2Mark = 0;
        }
        printf("Enter MOSS result for A3: ");
        scanf("%d", &mossA3);
        if (mossA3 == 0){
            a3Mark = 0;
        }
        finalAMark = (a1Mark * 0.05) + (a2Mark * 0.07) + (a3Mark * 0.08);
        printf("Overall assignment grade (20) = %.2lf / 20\n\n", finalAMark);
        
        //Calculating and displaying quiz marks
        printf("Enter 4 quiz marks, each separated by a space: ");
        scanf("%lf %lf %lf %lf", &quizMark1, &quizMark2, &quizMark3, &quizMark4);
        finalQuizMark = (quizMark1 * 0.05) + (quizMark2 * 0.05) + (quizMark3 * 0.05) + (quizMark4 * 0.05);  
        printf("Overall quiz grade (20) = %.2lf / 20\n\n", finalQuizMark);

        //Calculating and displaying lab exam mark with option to transfer weight
        printf("Enter lab exam mark: ");
        scanf("%lf", &labExamMark);
        printf("Enter the survey response ('y' or 'n'): ");
        scanf(" %c", &surveyResp);
        if (surveyResp == 'y'){
            printf("Your lab exam is worth 0, and final exam is worth 40\n\n");
            finalLabExamMark = 0.00;
            examWeight = 0.4;
            overallExamWeight = 40;
        }
        if (surveyResp == 'n'){
            printf("Your lab exam is worth 10, and final exam is worth 30\n\n");
            examWeight = 0.3;
            finalLabExamMark = labExamMark * 0.1;
            overallExamWeight = 30;
        }

        //Calculating and displaying final exam mark with selected weightage
        printf("Enter final exam mark: ");
        scanf("%lf", &examMark);
        finalExamMark1 = examMark * examWeight;
        finalExamMark2 = examMark * 0.3;
        printf("Overall final exam grade (%d) = %.2lf / %d\n\n", overallExamWeight, finalExamMark1, overallExamWeight);
        
        //Calculating and displaying total quiz and exam marks
        finalQuizExamMark = finalQuizMark + finalExamMark2;
        if (finalQuizExamMark < 25){
            printf("Quizzes + Final Exam = %.2lf + %.2lf = %.2lf (< 25)\n\n", finalQuizMark, finalExamMark2, finalQuizExamMark);
        }
        if (finalQuizExamMark >= 25){
            printf("Quizzes + Final Exam = %.2lf + %.2lf = %.2lf (>= 25)\n\n", finalQuizMark, finalExamMark2, finalQuizExamMark);
        }

        //Displaying overall marks
        printf("Overall course marks (%%) \n");
        printf("*************************\n");
        printf("Labs = %.2lf\n", finalLabMark);
        printf("Assignments = %.2lf\n", finalAMark);
        printf("Quizzes = %.2lf\n", finalQuizMark);
        if (overallExamWeight == 30){
            printf("Lab Exam = %.2lf\n", finalLabExamMark);
        }
        printf("Final Exam = %.2lf\n", finalExamMark1);
        printf("*************************\n\n");

        //Checking student mark and displaying a final grade
        overallCourseMark = finalLabMark + finalAMark + finalQuizMark + finalLabExamMark + finalExamMark1;
        if (mossA1 == 0 && mossA2 == 0 && mossA3 == 0){
            overallCourseMark = 0.00;
            printf("All your assignments were flagged for plagiarism, and therefore\n");
        }
        printf("Your overall course marks = %.2lf %%\n", overallCourseMark);
        
        if (overallCourseMark >= 80 && overallCourseMark <= 100){
            printf("Overall grade = A\n\n");
        }
        if (overallCourseMark >= 70 && overallCourseMark <= 79){
            printf("Overall grade = B\n\n");
        }
        if (overallCourseMark >= 60 && overallCourseMark <= 69){
            printf("Overall grade = C\n\n");
        }
        if (overallCourseMark >= 50 && overallCourseMark <= 59){
            printf("Overall grade = D\n\n");
        }
        if ((overallCourseMark >= 0.00 && overallCourseMark<=49) || (finalQuizExamMark < 25)){
            printf("Overall grade = F\n\n");
        }

        //Checking if user would like to continue to next student and storing total student marks
        printf("Would you like to continue ('y' to continue, 'n' to exit):");
        scanf(" %c", &userResponse);
        totalMarks = totalMarks + overallCourseMark;
    }

    //When user exits, calculate and displays the average course mark for the amount of students
    avgMark = totalMarks/studentNum;
    printf("Average course mark of %d students = %.2lf %%", studentNum, avgMark);
    
    return 0;
}