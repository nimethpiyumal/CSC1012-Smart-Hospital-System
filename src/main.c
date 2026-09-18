#include <stdio.h>
#include "hospital.h"

int main(void) {
    int choice;
    int patientNum;


    initBedOccupancy();

    do {
        printf("\n===================================================\n");
        printf("      SMART HOSPITAL RESOURCE ALLOCATION SYSTEM    \n");
        printf("===================================================\n");
        printf("1. Register New Patient\n");
        printf("2. View Bed Occupancy Status\n");
        printf("3. Print Patient Bill & Invoice\n");
        printf("4. Sort Patient Queue by Priority (Urgency Level)\n");
        printf("5. View Summary Reports & Analytics\n");
        printf("6. Exit\n");
        printf("===================================================\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerPatient();
                break;

            case 2:
                printBedStatus();
                break;

            case 3:
                if (totalPatients == 0) {
                    printf("\n[INFO] No patients registered yet.\n");
                } else {
                    printf("Enter Registered Patient Number (1 to %d): ", totalPatients);
                    scanf("%d", &patientNum);
                    if (patientNum >= 1 && patientNum <= totalPatients) {
                        generateBill(patientNum - 1);
                    } else {
                        printf("\n Invalid Patient Number!\n");
                    }
                }
                break;

            case 4:
                sortByPriority();
                break;

            case 5:
                generateReports();
                break;

            case 6:
                printf("\n Thank you for using Smart Hospital System. Goodbye!\n");
                break;

            default:
                printf("\n Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
