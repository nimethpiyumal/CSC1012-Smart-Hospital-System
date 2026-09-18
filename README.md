# Smart Hospital & Resource Allocation System

**Course:** CSC 1012 - Introduction to Computer Programming  
**University:** University of Sri Jayewardenepura - Faculty of Applied Sciences  
**Type:** Individual Assignment

## Project Objective
A modular, menu-driven Smart Hospital Patient & Resource Allocation System 
implemented in C, using parallel arrays, functions, string handling, loops, 
conditionals, mathematical modelling, and file handling to simulate patient 
intake, bed allocation, emergency triage sorting, and billing estimation.

## Features / Functional Requirements
1. Lookup Data & Bed Occupancy Matrix (doctor specialties, hospital wards)
2. Patient Intake & Data Registration
3. Billing & Waiting Time Calculations
4. Priority-based Patient Sorting (Urgency Level)
5. Formatted Bill Generation
6. Performance Reports & Analytics

## Data Structures (Parallel Arrays)
- Doctor specialty lookup arrays (ID, name, fee, consult time, daily cap)
- Ward lookup arrays (ID, name, daily rate, capacity)
- 2D bed occupancy matrix `bedOccupancy[4][20]`
- Patient parallel arrays (name, age, urgency, specialty, admission info, billing)

## Planned Functions
- `registerPatient()`
- `calculateSurcharge()`
- `calculateWardCost()`
- `calculateDiscount()`
- `generateBill()`
- `sortByPriority()`
- `generateReports()`

## Project Structure


main.c           Interactive menu loop & system entry
hospital.c       Lookup data & bed status matrix initialization
hospital.h       Central header file with prototypes & constants
patient.c        Patient intake and registration logic
billing.c        Fee, surcharge, discount, & invoice calculations
sorting.c        Bubble sort priority queue implementation
reports.c        Hospital statistics & summary reports
README.md        Project documentation