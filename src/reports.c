#include <stdio.h>
#include "hospital.h"


void generateReports(void) {
    if (totalPatients == 0) {
        printf("\nNo patients registered yet.\n");
        return;
    }

    int countL1 = 0, countL2 = 0, countL3 = 0;
    double totalRevenue = 0.0;
    double totalDiscountGiven = 0.0;
    double highestBill = -1.0;
    int highestBillPatientIdx = -1;


    for (int i = 0; i < totalPatients; i++) {
        if (urgencyLevel[i] == 1) countL1++;
        else if (urgencyLevel[i] == 2) countL2++;
        else if (urgencyLevel[i] == 3) countL3++;

        int specIdx = getSpecialtyIndexById(assignedSpecialty[i]);
        int wardIdx = (isAdmitted[i] == 1) ? getWardIndexById(assignedWard[i]) : -1;

        double fee = baseFee[specIdx];
        double sur = calculateSurcharge(fee, urgencyLevel[i]);
        double wardCost = calculateWardCost(wardIdx, daysAdmitted[i]);
        double gross = fee + sur + wardCost;
        double disc = calculateDiscount(patientAge[i], gross);
        double finalAmt = gross - disc;

        totalRevenue += finalAmt;
        totalDiscountGiven += disc;

        if (finalAmt > highestBill) {
            highestBill = finalAmt;
            highestBillPatientIdx = i;
        }
    }


    printf("\n--- HOSPITAL SUMMARY REPORT ---\n");
    printf("Total Registered Patients : %d\n", totalPatients);
    printf(" - Level 1 (Normal)       : %d\n", countL1);
    printf(" - Level 2 (Urgent)       : %d\n", countL2);
    printf(" - Level 3 (Critical)     : %d\n", countL3);

    printf("\nFinancial Summary:\n");
    printf(" - Total Revenue Earned   : LKR %.2f\n", totalRevenue);
    printf(" - Total Discounts Given  : LKR %.2f\n", totalDiscountGiven);

    printf("\nWard Occupancy Rates:\n");
    for (int i = 0; i < NUMWARDS; i++) {
        int occupiedCount = 0;
        for (int j = 0; j < totalBedCapacity[i]; j++) {
            if (bedOccupancy[i][j] == 1) {
                occupiedCount++;
            }
        }
        double occupancyPct = ((double)occupiedCount / totalBedCapacity[i]) * 100.0;
        printf(" - %s: %.1f%% (%d/%d beds)\n", wardName[i], occupancyPct, occupiedCount, totalBedCapacity[i]);
    }

    if (highestBillPatientIdx != -1) {
        printf("\nHighest Paying Patient   : %s (LKR %.2f)\n",
               patientName[highestBillPatientIdx], highestBill);
    }
