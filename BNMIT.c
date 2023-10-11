#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep function

// Define ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

struct AdmissionInfo {
    char name[50];
    char program[50]; // MBA or BE
    char discipline[50]; // Only for BE
    int rank;
    
    char previousClass[50];
    int yearOfPassing;
};

struct UserInfo {
    char name[50];
    char contact[20];
    char issue[200];
};


void displayAdmissionForm(char program[]) {
    struct AdmissionInfo applicant;
    printf(BLUE "Admission Form for %s Program:\n", program);

    strcpy(applicant.program, program);

    printf("Please enter your name: ");
    scanf("%s", applicant.name);
    printf("Please enter your rank: ");
    scanf("%d", &applicant.rank);
    printf("Please enter your previous class (e.g., 12th): ");
    scanf("%s", applicant.previousClass);
    printf("Please enter the year of passing your previous class: ");
    scanf("%d", &applicant.yearOfPassing);

    if (strcmp(program, "BE") == 0) {
        printf("Please select your discipline:\n");
        printf("1. Computer Science and Engineering\n");
        printf("2. Information Science and Engineering\n");
        printf("3. Mechanical Engineering\n");
        printf("4. Electrical and Electronics Engineering\n");
        printf("5. Civil Engineering\n");
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(applicant.discipline, "Computer Science and Engineering");
                break;
            case 2:
                strcpy(applicant.discipline, "Information Science and Engineering");
                break;
            case 3:
                strcpy(applicant.discipline, "Mechanical Engineering");
                break;
            case 4:
                strcpy(applicant.discipline, "Electrical and Electronics Engineering");
                break;
            case 5:
                strcpy(applicant.discipline, "Civil Engineering");
                break;
            default:
                strcpy(applicant.discipline, "Invalid Discipline");
                break;
        }
    }

    // Save the admission details to a file
    FILE *file = fopen("admission_details.txt", "a");
    if (file == NULL) {
        printf("Error opening file for saving admission details.\n");
    } else {
        fprintf(file, "Name: %s\nProgram: %s\n", applicant.name, applicant.program);
        if (strcmp(program, "BE") == 0) {
            fprintf(file, "Discipline: %s\n", applicant.discipline);
        }
        fprintf(file, "Rank: %d\nPrevious Class: %s\nYear of Passing: %d\n\n",
                applicant.rank, applicant.previousClass, applicant.yearOfPassing);
        fclose(file);
        printf("Thank you! Your admission details have been recorded.\n");
    }
}

void displayInfo(int choice) {
    switch (choice) {
        case 1:
            displayAdmissionForm("BE");
            break;
        case 2:
            displayAdmissionForm("MBA");
            break;
        case 3:
            // Display admission details in blue color
            printf(BLUE "Admission Details:\n");
            printf("B.E. (Bachelor of Engineering) Admission:\n");
            printf("The B.E. program at BNMIT College is offered in the following disciplines:\n");
            printf("1 Computer Science and Engineering\n");
            printf("2 Information Science and Engineering\n");
            printf("3 Mechanical Engineering\n");
            printf("4 Electrical and Electronics Engineering\n");
            printf("5 Civil Engineering\n");
            printf("For more information on admission, please visit our website: https://www.bnmit.edu.in/admissions\n");
            printf("MBA (Master of Business Administration) Admission:\n");
            printf("The MBA program at BNMIT College is offered in the following specializations:\n");
            printf("1 Finance\n");
            printf("2 Marketing\n");
            printf("3 Human Resource Management\n");
            printf("4 Operations Management\n");
            printf("For more information on admission, please visit our website: https://www.bnmit.edu.in/admissions\n" RESET);
            break;
        case 4:
            // Display fees information in green color
            printf(GREEN "Fees Information:\n");
            printf("The fees for the B.E. program at BNMIT College are as follows:\n");
            printf("* Tuition fee: Rs. 1 lakh per year\n");
            printf("* Hostel fee: Rs. 50,000 per year\n");
            printf("* Mess fee: Rs. 10,000 per year\n");
            printf("The fees for the MBA program at BNMIT College are as follows:\n");
            printf("* Tuition fee: Rs. 2 lakh per year\n");
            printf("* Hostel fee: Rs. 60,000 per year\n");
            printf("* Mess fee: Rs. 12,000 per year\n");
            printf("For more information on fees, please visit our website: https://www.bnmit.edu.in/fees\n" RESET);
            break;
        case 5:
            // Display campus details in yellow color
            printf(YELLOW "Campus Details:\n");
            printf("BNMIT College is located in Bengaluru, Karnataka. The campus is spread over 100 acres and has the following facilities:\n");
            printf("* Academic buildings\n");
            printf("* Hostels\n");
            printf("* Mess\n");
            printf("* Library\n");
            printf("* Sports facilities\n");
            printf("* Medical facilities\n");
            printf("* Wi-Fi connectivity\n" RESET);
            break;
        case 6:
            // Display achievements in red color
            printf(RED "Achievements:\n");
            printf("BNMIT College has a number of achievements, including:\n");
            printf("* The college has been ranked 33rd for B.E. programs by the National Institutional Ranking Framework (NIRF)\n");
            printf("* The college has been accredited by the National Board of Accreditation (NBA)\n");
            printf("* The college has won a number of awards, including the Karnataka State Vishwakarma Award\n");
            printf("* The college has produced a number of successful alumni, including entrepreneurs, engineers, and scientists\n" RESET);
            break;
        case 7:
            // Provide a link to a campus tour video in blue color
            printf(BLUE "Campus Tour:\n");
            printf("Take a virtual tour of our campus on YouTube: https://www.youtube.com/watch?v=abc123\n" RESET);
            break;
        case 8:
            // Handle "Other Issue" by asking the user for their details and issue
            struct UserInfo user;
            printf("Other Issue:\n");
            printf("Please enter your name: ");
            scanf("%s", user.name);
            printf("Please enter your contact information: ");
            scanf("%s", user.contact);
            printf("Please describe your issue: ");
            scanf("%s", user.issue);

            // Save the user's issue to a file (you can append it to "issues.txt" as before)
            FILE *file = fopen("issues.txt", "a");
            if (file == NULL) {
                printf("Error opening file for saving issue.\n");
            } else {
                fprintf(file, "Name: %s\nContact: %s\nIssue: %s\n\n", user.name, user.contact, user.issue);
                fclose(file);
                printf("Thank you! Your issue has been recorded.\n");
            }
            break;
        case 9:
            // Display contact details in blue color
            printf(BLUE "Contact Details:\n");
            printf("Website: www.bnmit.org\n");
            printf("Address:\n");
            printf("Post Box No. 7087,\n");
            printf("12th Main Road, 27th Cross,\n");
            printf("Banashankari II Stage,\n");
            printf("Bangalore – 560 070.\n");
            printf("Phone: +91-80-26711781\n");
            printf("Fax: +91-80-26711781\n" RESET);
            break;
            case 10:
              printf(CYAN "Scholarships:\n");
    printf("BNMIT College offers various scholarships to meritorious students:\n");
    printf("* Merit Scholarship for top rank holders\n");
    printf("* Need-based scholarships for economically disadvantaged students\n");
    printf("* Sports scholarships for outstanding athletes\n");
    printf("For more information on scholarships, please visit our website: https://www.bnmit.edu.in/scholarships\n" RESET);
                break;
                case 11:
                  printf(MAGENTA "Alumni Network:\n");
    printf("BNMIT College has a strong alumni network with successful professionals:\n");
    printf("* Alumni regularly participate in mentorship programs\n");
    printf("* Networking events and career guidance sessions are organized\n");
    printf("For more information on the alumni network, please visit our website: https://www.bnmit.edu.in/alumni\n" RESET);
    break;
            
        case 12:
            // Display exit message in green color and add a simple animation
            printf(GREEN "Thank you for using BNMIT College Chat Bot. Exiting");
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout); // Flush the output buffer to display the dots immediately
                sleep(1); // Sleep for 1 second
            }
            printf("\n" RESET);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
    }
}


int main() {
    int choice;
    
    printf("Welcome to BNMIT College Chat Bot\n");

    while (1) {
        printf("1. Apply for B.E. Admission\n");
        printf("2. Apply for MBA Admission\n");
        printf("3. Admission Details\n");
        printf("4. Fees Information\n");
        printf("5. Campus Details\n");
        printf("6. Achievements\n");
        printf("7. Campus Tour\n");
        printf("8. Other Issue\n");
        printf("9. Contact Details\n");
        printf("10. Scholarships deatils\n");
          printf("11. Alumni networking\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 12){
            if (choice == 3) {
                // Display admission details in blue color
                printf(BLUE "Admission Details:\n");
                printf("B.E. (Bachelor of Engineering) Admission:\n");
                printf("The B.E. program at BNMIT College is offered in the following disciplines:\n");
                printf("1 Computer Science and Engineering\n");
                printf("2 Information Science and Engineering\n");
                printf("3 Mechanical Engineering\n");
                printf("4 Electrical and Electronics Engineering\n");
                printf("5 Civil Engineering\n");
                printf("For more information on admission, please visit our website: https://www.bnmit.edu.in/admissions\n");
                printf("MBA (Master of Business Administration) Admission:\n");
                printf("The MBA program at BNMIT College is offered in the following specializations:\n");
                printf("1 Finance\n");
                printf("2 Marketing\n");
                printf("3 Human Resource Management\n");
                printf("4 Operations Management\n");
                printf("For more information on admission, please visit our website: https://www.bnmit.edu.in/admissions\n" RESET);
            } else {
                displayInfo(choice);
            }
            if (choice >= 1 && choice <= 11) {
                printf("\n Do you have any more questions? \nIf yes : 1\nIf no  : 0\n");
                int moreQuestions;
                scanf("%d", &moreQuestions);
                if (!moreQuestions) {
                    // Display exit message and exit
                    displayInfo(12);
                    break;
                }
            }else if(choice == 12)
            break;
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}