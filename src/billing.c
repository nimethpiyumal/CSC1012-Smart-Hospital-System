#include <stdio.h>
#include "hospital.h"


double calculateSurcharge(double fee, int urgency) {
    if (urgency == 2) {
        return fee * 0.20;
    } else if (urgency == 3) {
        return fee * 0.50;
    }
    return 0.0;
}


double calculateWardCost(int wardIdx, int days) {
    if (wardIdx < 0 || days <= 0) return 0.0;
    return dailyBedRate[wardIdx] * days;
}


double calculateDiscount(int age, double grossTotal) {
    if (age < 5 || age > 65) {
        return grossTotal * 0.15;
    }
    return 0.0;
}


void generateBill(int i) {
    if (i < 0 || i >= totalPatients) {
        printf("\n[ERROR] Invalid patient index!\n");
        return;
    }

    int specIdx = getSpecialtyIndexById(assignedSpecialty[i]);
    int wardIdx = (isAdmitted[i] == 1) ? getWardIndexById(assignedWard[i]) : -1;

    double fee = baseFee[specIdx];
    double surcharge = calculateSurcharge(fee, urgencyLevel[i]);
    double wardCost = calculateWardCost(wardIdx, daysAdmitted[i]);

    double grossTotal = fee + surcharge + wardCost;


    double discount = calculateDiscount(patientAge[i], grossTotal);


    double finalPayable = grossTotal - discount;


    double waitTime = (queueCount[specIdx] > 0) ? (queueCount[specIdx] - 1) * consultTimeMins[specIdx] : 0.0;
    if (urgencyLevel[i] == 3) waitTime = 0.0;

    printf("\n===============================================================\n");
    printf("                  SMART HOSPITAL ADMISSION & BILL               \n");
    printf("===============================================================\n");
    printf("Patient ID             : PAT-%d\n", 1001 + i);
    printf("Patient Name           : %s\n", patientName[i]);
    printf("Age                    : %d Years %s\n", patientAge[i], (patientAge[i] < 5 || patientAge[i] > 65) ? "(15% Subsidy Eligible)" : "");
    printf("Specialty              : %s\n", specialtyName[specIdx]);

    if (isAdmitted[i] == 1 && wardIdx != -1) {
        printf("Assigned Ward          : %s (Bed #%02d)\n", wardName[wardIdx], assignedBed[i]);
    } else {
        printf("Assigned Ward          : Outpatient (OPD)\n");
    }

    printf("Urgency Level          : Level %d (%s)\n", urgencyLevel[i],
            (urgencyLevel[i] == 3) ? "Critical" : (urgencyLevel[i] == 2) ? "Urgent" : "Normal");

    printf("---------------------------------------------------------------\n");
    printf("Base Consultation Fee  : LKR %10.2f\n", fee);
    printf("Emergency Surcharge    : LKR %10.2f\n", surcharge);
    printf("Ward Stay Cost (%d Days): LKR %10.2f\n", daysAdmitted[i], wardCost);
    printf("---------------------------------------------------------------\n");
    printf("Gross Total Bill       : LKR %10.2f\n", grossTotal);
    printf("Age Subsidy Discount   : LKR -%9.2f\n", discount);
    printf("---------------------------------------------------------------\n");
    printf("Final Payable Amount   : LKR %10.2f\n", finalPayable);
    printf("Estimated Waiting Time : %.2f mins %s\n", waitTime, (urgencyLevel[i] == 3) ? "(Immediate Attention)" : "");
    printf("===============================================================\n");
}
