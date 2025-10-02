#include <stdio.h>
#include <string.h>

// Student structure
struct Stu {
    int roll;
    char name[30];
    int marks[5];
    float cgpa;
    float att;   // attendance
};

// Teacher structure
struct Tch {
    int id;
    char name[30];
    char sub[20];
};

// Staff structure
struct Stf {
    int id;
    char name[30];
    char pos[20];
};

int main() {
    struct Stu stu[50];
    struct Tch tch[20];
    struct Stf stf[20];

    int sc = 0, tc = 0, fc = 0; // counters
    int choice;

    do {
        printf("\n===== College Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Add Teacher\n");
        printf("3. Add Staff\n");
        printf("4. Show Students\n");
        printf("5. Show Teachers\n");
        printf("6. Show Staff\n");
        printf("7. Search Student by Roll\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add student
                if(sc < 50) {
                    struct Stu *s = &stu[sc]; // shortcut pointer

                    printf("Roll: ");
                    scanf("%d", &s->roll);
                    printf("Name: ");
                    scanf("%s", s->name);

                    int total = 0;
                    printf("Enter 5 subject marks: ");
                    for(int j=0; j<5; j++) {
                        scanf("%d", &s->marks[j]);
                        total += s->marks[j];
                    }

                    float per = total / 5.0;
                    s->cgpa = per / 9.5;  // approx formula
                    printf("Attendance %%: ");
                    scanf("%f", &s->att);

                    sc++;
                } else {
                    printf("Student list full!\n");
                }
                break;

            case 2: // Add teacher
                if(tc < 20) {
                    struct Tch *t = &tch[tc];

                    printf("ID: ");
                    scanf("%d", &t->id);
                    printf("Name: ");
                    scanf("%s", t->name);
                    printf("Subject: ");
                    scanf("%s", t->sub);

                    tc++;
                } else {
                    printf("Teacher list full!\n");
                }
                break;

            case 3: // Add staff
                if(fc < 20) {
                    struct Stf *st = &stf[fc];

                    printf("ID: ");
                    scanf("%d", &st->id);
                    printf("Name: ");
                    scanf("%s", st->name);
                    printf("Position: ");
                    scanf("%s", st->pos);

                    fc++;
                } else {
                    printf("Staff list full!\n");
                }
                break;

            case 4: // Show students
                printf("\n--- Student List ---\n");
                for(int i=0; i<sc; i++) {
                    struct Stu s = stu[i]; // shortcut
                    printf("Roll: %d, Name: %s\n", s.roll, s.name);
                    printf("Marks: ");
                    for(int j=0; j<5; j++) {
                        printf("%d ", s.marks[j]);
                    }
                    printf("\nCGPA: %.2f, Attendance: %.2f%%\n\n", s.cgpa, s.att);
                }
                break;

            case 5: // Show teachers
                printf("\n--- Teacher List ---\n");
                for(int i=0; i<tc; i++) {
                    struct Tch t = tch[i];
                    printf("ID: %d, Name: %s, Subject: %s\n", t.id, t.name, t.sub);
                }
                break;

            case 6: // Show staff
                printf("\n--- Staff List ---\n");
                for(int i=0; i<fc; i++) {
                    struct Stf st = stf[i];
                    printf("ID: %d, Name: %s, Position: %s\n", st.id, st.name, st.pos);
                }
                break;

            case 7: { // Search student
                int roll, found = 0;
                printf("Enter Roll to search: ");
                scanf("%d", &roll);

                for(int i=0; i<sc; i++) {
                    if(stu[i].roll == roll) {
                        struct Stu s = stu[i];
                        printf("\n--- Student Found ---\n");
                        printf("Roll: %d, Name: %s\n", s.roll, s.name);
                        printf("CGPA: %.2f, Attendance: %.2f%%\n", s.cgpa, s.att);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Student not found!\n");
                }
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
