#include<stdio.h>


int main () {
    int credit=0, total=0, a, grade, p_or_m;
    float gpa, score = 0;
    a = getchar();
    while (a != '\n'){
        credit = a - '0';
        grade = getchar();
        switch (grade){
            case 'A':
                if ((p_or_m = getchar()) == '+'){
                    score += (4.3f * credit);
                    total += credit;
                    a = getchar();
                    break;
                }
                else if (p_or_m == '-'){
                    score += (3.7f * credit);
                    total += credit;
                    a = getchar();
                    break;
                }
                else{
                    score += (4.0f * credit);
                    total += credit;
                    a = p_or_m;
                    break;
                }
            case 'B':
                if ((p_or_m = getchar()) == '+'){
                    score += (3.3f * credit);
                    total += credit;
                    a = getchar();
                    break;
                }
                else if (p_or_m == '-'){
                    score += (2.7f * credit);
                    total += credit;
                    a = getchar();
                    break;
                }
                else{
                    score += (3.0f * credit);
                    total += credit;
                    a = p_or_m;
                    break;
                }
            case 'C':
                if ((p_or_m = getchar()) == '+'){
                    score += (2.3f * credit);
                    total += credit;
                    a = getchar();
                    break;
                }
                else if (p_or_m == '-'){
                    score += (1.7f * credit);
                    total += credit;
                    a = getchar();
                    break;
                }
                else{
                    score += (2.0f * credit);
                    total += credit;
                    a = p_or_m;
                    break;
                }
            case 'F':
                score += (0.0f * credit);
                total += credit;
                a = getchar();
                break;
            default:
                break;
        }
        
    }
    gpa = score / total;
    printf("%.2f",gpa);
    return 0;
}
