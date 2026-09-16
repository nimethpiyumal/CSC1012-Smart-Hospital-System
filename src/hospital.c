#include <stdio.h>
#include "hospital.h"


int bedOccupancy[NUMWARDS][MAXBEDSPERWARD];
int queueCount[NUMSPECIALTIES] = {0, 0, 0, 0};


void initBedOccupancy(void) {
    for (int i = 0; i < NUMWARDS; i++) {
        for (int j = 0; j < MAXBEDSPERWARD; j++) {
            bedOccupancy[i][j] = 0;
        }
    }
}


int getWardIndexById(int id) {
    for (int i = 0; i < NUMWARDS; i++) {
        if (wardID[i] == id) {
            return i;
        }
    }
    return -1;
}


int getSpecialtyIndexById(int id) {
    for (int i = 0; i < NUMSPECIALTIES; i++) {
        if (specialtyID[i] == id) {
            return i;
        }
    }
    return -1;
}


int findAvailableBed(int wardIndex) {
    if (wardIndex < 0 || wardIndex >= NUMWARDS) return -1;

    int capacity = totalBedCapacity[wardIndex];
    for (int j = 0; j < capacity; j++) {
        if (bedOccupancy[wardIndex][j] == 0) {
            return j;
        }
    }
    return -1;
}


void printBedStatus(void) {
    printf("\n================ HOSPITAL BED OCCUPANCY STATUS ================\n");
    for (int i = 0; i < NUMWARDS; i++) {
        printf("\n%s (Capacity: %d):\n", wardName[i], totalBedCapacity[i]);
        for (int j = 0; j < totalBedCapacity[i]; j++) {
            printf("[Bed %02d: %s] ", j + 1, bedOccupancy[i][j] ? "OCCUPIED" : "FREE");
            if ((j + 1) % 5 == 0) printf("\n");
        }
        printf("\n");
    }
    printf("===============================================================\n");
}
