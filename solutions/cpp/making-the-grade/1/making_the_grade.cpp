#include <array>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

// 1. Redondeo de puntuacion
vector<int> round_down_scores(vector<double> student_scores) {
    vector<int> rounded;
    for (double score : student_scores) rounded.push_back(static_cast<int>(score));
    return rounded;
}

// 2. Conteo de estudiantes reprobados
int count_failed_students(vector<int> student_scores) {
    int failed = 0;
    for (int score : student_scores)
        if (score <= 40) failed++;
    return failed;
}

// 3. Calificaciones con letras
array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - 40)/4;
    array <int, 4>thresholds;
    for (int i = 0; i < 4; i++) thresholds[i]= 41 + (interval * i);
    return thresholds;
}

// 4. Correspondencia de nombres (Ranking)
vector<string> student_ranking(
    vector<int> student_scores, vector<string> student_names) {
    vector<string> ranking;
    for (size_t i = 0; i < student_scores.size(); i++){
        string entry = to_string(i + 1) + ". " + student_names[i] + ": " + to_string(student_scores[i]);
        ranking.push_back(entry);
    }
    return ranking;
}

// 5. La puntuación perfecta
string perfect_score(vector<int> student_scores, vector<string> student_names) {
    for (size_t i = 0; i < student_scores.size(); i++)
        if (student_scores[i] == 100) return student_names[i];
    return "";
}
