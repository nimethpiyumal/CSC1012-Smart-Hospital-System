#include <stdio.h>
#include <string.h>
#include "hospital.h"


char patientName[MAXPATIENTS][50];
int  patientAge[MAXPATIENTS];
int  urgencyLevel[MAXPATIENTS];
int  assignedSpecialty[MAXPATIENTS];
int  isAdmitted[MAXPATIENTS];
int  assignedWard[MAXPATIENTS];
int  assignedBed[MAXPATIENTS];
int  daysAdmitted[MAXPATIENTS];

int totalPatients = 0;

void registerPatient(void) {
    if (totalPatients >= MAXPATIENTS) {
        printf("\n[ERROR] System full! Cannot register more patients.\n");
        return;
    }

    int i = totalPatients;

    printf("\n================ PATIENT REGISTRATION ================\n");


    printf("Enter Patient Name: ");
    getchar();
    fgets(patientName[i], 50, stdin);
    patientName[i][strcspn(patientName[i], "\n")] = 0;


do {
    printf("Enter Patient Age: ");
    scanf("%d", &patientAge[i]);
    if (patientAge[i] < 0 ) {
        printf("Invalid age! Please enter a value greater than 0 \n");
    }
} while (patientAge[i] < 0 );

    do {
        printf("Enter Triage/Urgency Level (1 = Normal, 2 = Urgent, 3 = Critical): ");
        scanf("%d", &urgencyLevel[i]);
    } while (urgencyLevel[i] < 1 || urgencyLevel[i] > 3);


    printf("\n--- Specialty Selection ---\n");
    for (int k = 0; k < NUMSPECIALTIES; k++) {
        printf("%d. %s (Fee: LKR %.2f)\n", specialtyID[k], specialtyName[k], baseFee[k]);
    }
    do {
        printf("Select Specialty ID (1 to 4): ");
        scanf("%d", &assignedSpecialty[i]);
    } while (assignedSpecialty[i] < 1 || assignedSpecialty[i] > 4);


    int specIndex = getSpecialtyIndexById(assignedSpecialty[i]);
    if (specIndex != -1) {
        queueCount[specIndex]++;
    }


    do {
        printf("\nIs Patient Admitted to Ward? (1 = Yes, 0 = No): ");
        scanf("%d", &isAdmitted[i]);
    } while (isAdmitted[i] != 0 && isAdmitted[i] != 1);

    if (isAdmitted[i] == 1) {
        printf("\n--- Ward Selection ---\n");
        for (int k = 0; k < NUMWARDS; k++) {
            printf("%d. %s (Daily Rate: LKR %.2f)\n", wardID[k], wardName[k], dailyBedRate[k]);
        }
        do {
            printf("Select Ward ID (1 to 4): ");
            scanf("%d", &assignedWard[i]);
        } while (assignedWard[i] < 1 || assignedWard[i] > 4);

        printf("Enter Days Admitted: ");
        scanf("%d", &daysAdmitted[i]);


        int wardIdx = getWardIndexById(assignedWard[i]);
        int bedIdx = findAvailableBed(wardIdx);

        if (bedIdx != -1) {
            assignedBed[i] = bedIdx + 1;
            bedOccupancy[wardIdx][bedIdx] = 1;
            printf("[SUCCESS] Bed #%02d allocated in %s!\n", assignedBed[i], wardName[wardIdx]);
        } else {
            printf("[WARNING] No free beds available in %s! Assigned Bed: None.\n", wardName[wardIdx]);
            assignedBed[i] = 0;
        }
    } else {
        assignedWard[i] = 0;
        assignedBed[i] = 0;
        daysAdmitted[i] = 0;
    }

    totalPatients++;
    printf("\n[SUCCESS] Patient PAT-%d registered successfully!\n", 1000 + totalPatients);
    printf("======================================================\n");
}
