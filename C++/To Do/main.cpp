#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

void RgbText(int red, int green, int blue, const char* text) {
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", red, green, blue, text);
}

void Encerrar() {
    printf("\nPressione ENTER para continuar...");
    char x = '0';
    do {
        x = getchar();
    } while ('\n' != x);
    getchar();
}

void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
    void PrintLegend() {
    printf("\n");
    std::cout << "+-----------------------+" << std::endl;
    std::cout << "| Cores das prioridades |" << std::endl;
    std::cout << "+-----------------------+" << std::endl;
    std::cout << "| \x1b[38;2;255;0;0m\u2BC0 - Prioridade alta\x1b[0m   |" << std::endl;
    std::cout << "| \x1b[38;2;255;255;0m\u2BC0 - Prioridade média\x1b[0m  |" << std::endl;
    std::cout << "| \x1b[38;2;0;255;0m\u2BC0 - Prioridade baixa\x1b[0m  |" << std::endl;
    std::cout << "+-----------------------+" << std::endl;
}


void saveTasks(const std::string& filename, const std::vector<std::string>& tasks, const std::vector<int>& priorities, const std::vector<bool>& completed, int numTasks) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numTasks; ++i) {
            file << tasks[i] << "|" << priorities[i] << "|" << (completed[i] ? "1" : "0") << std::endl;
        }
        file.close();
        std::cout << "Tarefas salvas em " << filename << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar as tarefas." << std::endl;
    }
}

void loadTasks(const std::string& filename, std::vector<std::string>& tasks, std::vector<int>& priorities, std::vector<bool>& completed, int& numTasks) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        numTasks = 0;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string description;
            std::string priorityStr;
            std::string completedStr;
            if (std::getline(ss, description, '|') && std::getline(ss, priorityStr, '|') && std::getline(ss, completedStr)) {
                tasks.push_back(description);
                priorities.push_back(std::stoi(priorityStr));
                completed.push_back(completedStr == "1");
                numTasks++;
            }
        }
        file.close();
        std::cout << "Tarefas carregadas de " << filename << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para carregar as tarefas." << std::endl;
    }
}

void addTask(std::vector<std::string>& tasks, std::vector<int>& priorities, std::vector<bool>& completed, int& numTasks, const std::string& task, int priority) {
    if (numTasks < 15) {
        tasks.push_back(task);
        priorities.push_back(priority);
        completed.push_back(false);
        numTasks++;
        RgbText(0, 200, 0, "\nTarefa adicionada com sucesso.\n");
    } else {
        std::cerr << "A lista de tarefas está cheia." << std::endl;
    }
    Encerrar();
}

void listTasks(const std::vector<std::string>& tasks, const std::vector<int>& priorities, const std::vector<bool>& completed, int numTasks) {
    LimparTela();
    int countTarefa = 0;
    PrintLegend();
    RgbText(138, 43, 226, "\n======== TAREFAS ========\n");
    if (numTasks == 0) {
        std::cerr << "Nenhuma tarefa pendente." << std::endl;
    } else {
        for (int i = 0; i < numTasks; ++i) {
            if (!completed[i]) {
                std::cout << "Tarefa " << i + 1 << ": ";
                if (priorities[i] == 1) {
                    RgbText(255, 0, 0, tasks[i].c_str());
                } else if (priorities[i] == 2) {
                    RgbText(255, 255, 0, tasks[i].c_str());
                } else {
                    RgbText(0, 255, 0, tasks[i].c_str());
                }
                std::cout << std::endl;
                countTarefa++;
            }
        }
        if (countTarefa == 0) {
            std::cerr << "Nenhuma tarefa pendente." << std::endl;
        }
    }
    RgbText(128, 128, 128, "\n\n======= CONCLUÍDAS ======\n");
    int countConc = 0;
    for (int i = 0; i < numTasks; ++i) {
        if (completed[i]) {
            std::cout << "\x1b[38;2;128;128;128mTarefa\x1b[0m " << i + 1 << "\x1b[38;2;128;128;128m:\x1b[0m ";
            RgbText(128, 128, 128, tasks[i].c_str());
            std::cout << std::endl;
            countConc++;
        }
    }
    if (countConc == 0) {
        std::cerr << "Nenhuma tarefa concluída." << std::endl;
    }
    Encerrar();
}

void markTaskCompleted(std::vector<bool>& completed, int taskIndex) {
    if (!completed[taskIndex] == true) {
        if (taskIndex >= 0 && taskIndex < completed.size()) {
            completed[taskIndex] = true;
        RgbText(0, 200, 0, "\nTarefa marcada como concluida.\n");
        } else {
            std::cerr << "\nÍndice de tarefa inválido." << std::endl;
        }
    } else {
        std::cout << "Tarefa já concluída." << std::endl;
    }

    Encerrar();
}

void deleteTask(std::vector<std::string>& tasks, std::vector<int>& priorities, std::vector<bool>& completed, int& numTasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < numTasks) {
        tasks.erase(tasks.begin() + taskIndex);
        priorities.erase(priorities.begin() + taskIndex);
        completed.erase(completed.begin() + taskIndex);
        numTasks--;
        RgbText(0, 200, 0, "\nTarefa deletada com sucesso.\n");
    } else {
        std::cerr << "\nÍndice de tarefa inválido." << std::endl;
    }

    Encerrar();
}

int main() {
    const std::string filename = "tasks.txt";
    std::vector<std::string> tasks;
    std::vector<int> priorities;
    std::vector<bool> completed;
    int numTasks = 0;

    loadTasks(filename, tasks, priorities, completed, numTasks);

    int choice;

    while (true) {
        LimparTela();
        RgbText(0, 255, 255, "\n======== Menu ========\n");
        std::cout << "1. Adicionar nova tarefa\n";
        std::cout << "2. Listar tarefas\n";
        std::cout << "3. Marcar tarefa como concluída\n";
        std::cout << "4. Deletar tarefa\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string newTask;
            int priority;

            std::cout << "\nDigite a tarefa: ";
            std::cin.ignore();
            std::getline(std::cin, newTask);
            std::cout << "Digite a prioridade (1-3, onde 3 é a menor): ";
            std::cin >> priority;

            addTask(tasks, priorities, completed, numTasks, newTask, priority);
        } else if (choice == 2) {
            listTasks(tasks, priorities, completed, numTasks);
        } else if (choice == 3) {
            int taskIndex;
            std::cout << "Digite o número da tarefa a ser marcada como concluída: ";
            std::cin >> taskIndex;
            markTaskCompleted(completed, taskIndex - 1);
        } else if (choice == 4) {
            int taskIndex;
            std::cout << "Digite o número da tarefa a ser deletada: ";
            std::cin >> taskIndex;
            deleteTask(tasks, priorities, completed, numTasks, taskIndex - 1);
        } else if (choice == 0) {
            saveTasks(filename, tasks, priorities, completed, numTasks);
            break;
        } else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }
    return 0;
}
