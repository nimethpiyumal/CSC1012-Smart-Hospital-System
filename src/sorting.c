#include <stdio.h>
#include <string.h>
#include "hospital.h"


void sortByPriority(void) {
    if (totalPatients <= 1) {
        printf("\n Not enough patients to sort\n");
        return;
    }

    for (int i = 0; i < totalPatients - 1; i++) {
        for (int j = 0; j < totalPatients - i - 1; j++) {


            if (urgencyLevel[j] < urgencyLevel[j + 1]) {


                int tempUrgency = urgencyLevel[j];
                urgencyLevel[j] = urgencyLevel[j + 1];
                urgencyLevel[j + 1] = tempUrgency;


                char tempName[50];
                strcpy(tempName, patientName[j]);
                strcpy(patientName[j], patientName[j + 1]);
                strcpy(patientName[j + 1], tempName);


                int tempAge = patientAge[j];
                patientAge[j] = patientAge[j + 1];
                patientAge[j + 1] = tempAge;


                int tempSpec = assignedSpecialty[j];
                assignedSpecialty[j] = assignedSpecialty[j + 1];
                assignedSpecialty[j + 1] = tempSpec;


                int tempAdmitted = isAdmitted[j];
                isAdmitted[j] = isAdmitted[j + 1];
                isAdmitted[j + 1] = tempAdmitted;


                int tempWard = assignedWard[j];
                assignedWard[j] = assignedWard[j + 1];
                assignedWard[j + 1] = tempWard;


                int tempBed = assignedBed[j];
                assignedBed[j] = assignedBed[j + 1];
                assignedBed[j + 1] = tempBed;


                int tempDays = daysAdmitted[j];
                daysAdmitted[j] = daysAdmitted[j + 1];
                daysAdmitted[j + 1] = tempDays;
            }
        }
    }

}
