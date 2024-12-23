#include <stdio.h>

void calculate_CH_grade(int score, int *points, int *rank_points) {
    if (score >= 45) {
        *points = 6;
        *rank_points = 7;
    } else if (score >= 43) {
        *points = 6;
        *rank_points = 6;
    } else if (score >= 41) {
        *points = 6;
        *rank_points = 5;
    } else if (score >= 36) {
        *points = 4;
        *rank_points = 4;
    } else if (score >= 31) {
        *points = 4;
        *rank_points = 3;
    } else if (score >= 19) {
        *points = 4;
        *rank_points = 2;
    } else {
        *points = 2;
        *rank_points = 1;
    }
}

void calculate_SO_grade(int score, int *points, int *rank_points) {
    if (score >= 61) {
        *points = 6;
        *rank_points = 7;
    } else if (score >= 59) {
        *points = 6;
        *rank_points = 6;
    } else if (score >= 56) {
        *points = 6;
        *rank_points = 5;
    } else if (score >= 48) {
        *points = 4;
        *rank_points = 4;
    } else if (score >= 39) {
        *points = 4;
        *rank_points = 3;
    } else if (score >= 23) {
        *points = 4;
        *rank_points = 2;
    } else {
        *points = 2;
        *rank_points = 1;
    }
}

void calculate_SC_grade(int score, int *points, int *rank_points) {
    if (score >= 52) {
        *points = 6;
        *rank_points = 7;
    } else if (score >= 50) {
        *points = 6;
        *rank_points = 6;
    } else if (score >= 46) {
        *points = 6;
        *rank_points = 5;
    } else if (score >= 38) {
        *points = 4;
        *rank_points = 4;
    } else if (score >= 31) {
        *points = 4;
        *rank_points = 3;
    } else if (score >= 20) {
        *points = 4;
        *rank_points = 2;
    } else {
        *points = 2;
        *rank_points = 1;
    }
}

void calculate_EN_grade(float score, int *points, int *rank_points) {
    if (score >= 98.05) {
        *points = 6;
        *rank_points = 7;
    } else if (score >= 95.15) {
        *points = 6;
        *rank_points = 6;
    } else if (score >= 90.24) {
        *points = 6;
        *rank_points = 5;
    } else if (score >= 81.58) {
        *points = 4;
        *rank_points = 4;
    } else if (score >= 69.83) {
        *points = 4;
        *rank_points = 3;
    } else if (score >= 38.75) {
        *points = 4;
        *rank_points = 2;
    } else {
        *points = 2;
        *rank_points = 1;
    }
}

// 數學的分級
void calculate_MA_grade(float score, int *points, int *rank_points) {
    if (score >= 94.23) {
        *points = 6;
        *rank_points = 7;
    } else if (score >= 90.19) {
        *points = 6;
        *rank_points = 6;
    } else if (score >= 81.73) {
        *points = 6;
        *rank_points = 5;
    } else if (score >= 72.12) {
        *points = 4;
        *rank_points = 4;
    } else if (score >= 63.08) {
        *points = 4;
        *rank_points = 3;
    } else if (score >= 40.96) {
        *points = 4;
        *rank_points = 2;
    } else {
        *points = 2;
        *rank_points = 1;
    }
}


int main() {
    int CH, SO, SC;
    float EN, MA;
    int points[5], rank_points[5];

    // 輸入五科成績
    scanf("%d %f %f %d %d", &CH, &EN, &MA, &SO, &SC);

    // 計算各科成績
    calculate_CH_grade(CH, &points[0], &rank_points[0]);
    calculate_EN_grade(EN, &points[1], &rank_points[1]);
    calculate_MA_grade(MA, &points[2], &rank_points[2]);
    calculate_SO_grade(SO, &points[3], &rank_points[3]);
    calculate_SC_grade(SC, &points[4], &rank_points[4]);

    // 計算總積分和總積點
    int total_points = 0, total_rank_points = 0;
    for (int i = 0; i < 5; i++) {
        total_points += points[i];
        total_rank_points += rank_points[i];
    }

    // 計算等級組合
    int count_A = 0, count_B = 0, count_C = 0;
    for (int i = 0; i < 5; i++) {
        if (points[i] == 6) count_A++;
        else if (points[i] == 4) count_B++;
        else if (points[i] == 2) count_C++;
    }

    // 輸出結果
    printf("%d/%d(", total_points, total_rank_points);
    if (count_A != 0) {
        printf("%dA", count_A);
    }
    if (count_B != 0) {
        printf("%dB", count_B);
    }
    if (count_C != 0) {
        printf("%dC", count_C);
    }
    printf(")\n");
    return 0;
}