#include "solution.h"
#include "ui_solution.h"
#include <algorithm>
#include <QFileDialog>
#include <QMessageBox>

solution::solution(std::vector<city*> cities, std::vector<road*> roads,
                   QString starting_city, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::solution)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::released, this, &solution::close);
    int n = 0;
    for (auto i : cities) {
        city_names.push_back(i->name);
        matrix.emplace_back();
        for (int j = 0; j < n; ++j) {
            matrix[n].push_back(-1);
        }
        for (int j = 0; j < n + 1; ++j) {
            matrix[j].push_back(-1);
        }
        ++n;
    }
    solution_text = "Для удобства присвоим городам номера:\n";
    n = 1;
    for (auto i : city_names) {
        solution_text += i + ":" + QString::fromStdString(std::to_string(n)) + ' ';
        ++n;
    }
    for (auto i : roads) {
        int first_city_index = std::distance(city_names.begin(),
                                             std::find(city_names.begin(),
                                                       city_names.end(),
                                                       i->first_city->name));
        int second_city_index = std::distance(city_names.begin(),
                                             std::find(city_names.begin(),
                                                       city_names.end(),
                                                       i->second_city->name));
        matrix[first_city_index][second_city_index] = i->length;
    }
    int starting_city_index = std::distance(city_names.begin(),
                                                                    std::find(city_names.begin(),
                                                                              city_names.end(),
                                                                              starting_city));
    solution_text += "\nМатрица смежности:\n";
    print_matrix(matrix, matrix.size());
    route = solve(matrix, starting_city_index);
    QString answer;
    if (route.size() == city_names.size()+1) {
        for (auto i : route) {
            answer += city_names[i] + "->";
        }
        answer.resize(answer.size() - 2);
        double length = 0;
        int last_city = route[0];
        for (auto it = ++route.begin(); it != route.end(); it++) {
            length += matrix[last_city][*it];
            last_city = *it;
        }
        answer += ". Длина всего пути: " + double_to_str(length);
        solution_text += "\nМаршрут:" + answer;
    } else {
        solution_text += "\nПосещены не все города! Искомого пути не существует!";
        answer = "Нет такого пути!";
    }
    ui->answerLable->setText(ui->answerLable->text() + ' ' + answer);
    ui->solutionBrowser->setText(solution_text);
}

QString solution::double_to_str(double in){
    QString result = QString::fromStdString(std::to_string(in));
    double intpart;
    while (result.back() == '0'){
        result.remove(result.length() - 1, 1);
    }
    if (modf(in, &intpart) == 0.0){
        result.remove(result.length() - 1, 1);
    }
    return result;
}

std::vector<int> solution::solve(std::vector<std::vector<double>> matrix,
                                 int starting_city){
    std::vector<std::pair<int, int>> branches;
    std::vector<int> route;
    matrix.emplace_back();
    for (int i = 0; i < matrix.size() - 1; ++i) {
        matrix[i].emplace_back();
        matrix[matrix.size() - 1].emplace_back();
    }
    matrix[matrix.size() - 1].push_back(-1);
    while (branches.size() < matrix.size() - 1) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            double min = INFINITY;
            for (int j = 0; j < matrix.size() - 1; ++j) {
                if (matrix[i][j] != -1 && matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            matrix[i][matrix.size() - 1] = min;
        }
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix.size() - 1; ++j) {
                if (matrix[i][j] != -1) {
                    matrix[i][j] -= matrix[i][matrix.size() - 1];
                }
            }
        }
        solution_text += "\nМатрица после редукции столбцов:\n";
        print_matrix(matrix, matrix.size() - 1);
        for (int i = 0; i < matrix.size() - 1; ++i) {
            double min = INFINITY;
            for (int j = 0; j < matrix.size() - 1; ++j) {
                if (matrix[j][i] != -1 && matrix[j][i] < min) {
                    min = matrix[j][i];
                }
            }
            matrix[matrix.size() - 1][i] = min;
        }
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix.size() - 1; ++j) {
                if (matrix[j][i] != -1) {
                    matrix[j][i] -= matrix[matrix.size() - 1][i];
                }
            }
        }
        solution_text += "\nМатрица после редукции строк:\n";
        print_matrix(matrix, matrix.size() - 1);
        std::pair<int, int> branch;
        double max_sum = -1;
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix.size() - 1; ++j) {
                if (matrix[i][j] == 0) {
                    double min_row = INFINITY, min_column = INFINITY;
                    for (int k = 0; k < matrix.size() - 1; ++k) {
                        if (matrix[i][k] != -1 && k != j && matrix[i][k] < min_row) {
                            min_row = matrix[i][k];
                        }
                        if (matrix[k][j] != -1 && k != i && matrix[k][j] < min_column) {
                            min_column = matrix[k][j];
                        }
                    }
                    if (min_row + min_column > max_sum) {
                        branch.first = i;
                        branch.second = j;
                        max_sum = min_row + min_column;
                    }
                }
            }
        }
        solution_text += "\nДобавим найденный путь: " + double_to_str(branch.first) +
                "->" + double_to_str(branch.second) + ' ';
        for (int i = 0; i < matrix.size() - 1; ++i) {
            matrix[branch.first][i] = -1;
            matrix[i][branch.second] = -1;
        }
        matrix[branch.first][branch.second] = -1;
        matrix[branch.second][branch.first] = -1;
        solution_text += "\nМатрица после редукции матрицы:\n";
        print_matrix(matrix, matrix.size() - 1);
        branches.push_back(branch);

    }
    solution_text += "\nПолученные пути:\n";
    for (auto i : branches) {
        solution_text += double_to_str(i.first) + "->" + double_to_str(i.second) + ' ';
    }
    route.push_back(starting_city);
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = 0; j < matrix.size() - 1; ++j) {
            if (branches[j].first == route.back()) {
                route.push_back(branches[j].second);
                break;
            }
        }
    }
    return route;
}

void solution::print_matrix(std::vector<std::vector<double>> matrix, int size) {
    std::vector<std::vector<QString>> matrix_to_print;
    std::vector<std::vector<QString>> matrix_separetion;
    std::vector<int> max_size;
    for (int i = 0; i < size; ++i) {
        std::vector<QString> *new_vec = new std::vector<QString>;
        matrix_to_print.push_back(*new_vec);
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == -1) {
                matrix_to_print[i].push_back("*");
            } else {
                matrix_to_print[i].push_back(double_to_str(matrix[i][j]));
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        matrix_to_print[i].insert(matrix_to_print[i].begin(), double_to_str(i + 1));
    }
    matrix_to_print.emplace(matrix_to_print.begin());
    matrix_to_print[0].push_back("");
    for (int i = 0; i < size; ++i) {
        matrix_to_print[0].push_back(double_to_str(i + 1));
    }
    for (int i = 0; i < matrix_to_print.size(); ++i){
        max_size.push_back(0);
        for (int j = 0; j < matrix_to_print.size(); ++j) {
            if (matrix_to_print[j][i].length() > max_size[i]) {
                max_size[i] = matrix_to_print[j][i].length();
            }
        }
    }
    for (int i = 0; i < matrix_to_print.size(); ++i){
        std::vector<QString> *new_vec = new std::vector<QString>;
        matrix_separetion.push_back(*new_vec);
        for (int j = 0; j < matrix_to_print.size(); ++j){
            matrix_separetion[i].push_back("");
            for (int k = 0; k < max_size[j] - matrix_to_print[i][j].length(); ++k){
                matrix_separetion[i][j] += ' ';
            }
        }
    }
    for (int i = 0; i < matrix_to_print.size(); ++i) {
        for (int j = 0; j < matrix_to_print.size(); ++j) {
            solution_text += matrix_to_print[i][j] + ' ' + matrix_separetion[i][j];
        }
        solution_text += '\n';
    }
}

void solution::close() {
    solution::~solution();
}

void solution::return_solution() {
    if (route.size() == city_names.size()+1) emit solved(route);
}

solution::~solution()
{
    delete ui;
}
