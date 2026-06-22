#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ALUNOS = 50;

struct Aluno {
    string nome;
    float nota1;
    float nota2;
    float nota3;
    float media;
};

Aluno alunos[MAX_ALUNOS];
int quantidade = 0;

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

void cadastrarAluno() {

    if (quantidade >= MAX_ALUNOS) {
        cout << "Limite de alunos atingido!\n";
        return;
    }

    Aluno novo;

    cin.ignore();

    cout << "\nNome: ";
    getline(cin, novo.nome);

    cout << "Nota 1: ";
    cin >> novo.nota1;

    cout << "Nota 2: ";
    cin >> novo.nota2;

    cout << "Nota 3: ";
    cin >> novo.nota3;

    novo.media = calcularMedia(
        novo.nota1,
        novo.nota2,
        novo.nota3
    );

    alunos[quantidade] = novo;
    quantidade++;

    cout << "\nAluno cadastrado!\n";
}

void listarAlunos() {

    if (quantidade == 0) {
        cout << "\nNenhum aluno cadastrado.\n";
        return;
    }

    cout << "\n===== ALUNOS =====\n";

    for (int i = 0; i < quantidade; i++) {

        cout << "\nAluno " << i + 1 << endl;

        cout << "Nome: "
            << alunos[i].nome << endl;

        cout << "Media: "
            << fixed << setprecision(2)
            << alunos[i].media << endl;
    }
}

void buscarAluno() {

    string nome;

    cin.ignore();

    cout << "\nNome do aluno: ";
    getline(cin, nome);

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].nome == nome) {

            cout << "\nAluno encontrado!\n";

            cout << "Nome: "
                << alunos[i].nome << endl;

            cout << "Nota 1: "
                << alunos[i].nota1 << endl;

            cout << "Nota 2: "
                << alunos[i].nota2 << endl;

            cout << "Nota 3: "
                << alunos[i].nota3 << endl;

            cout << "Media: "
                << alunos[i].media << endl;

            return;
        }
    }

    cout << "\nAluno nao encontrado.\n";
}

void editarNotas() {

    string nome;

    cin.ignore();

    cout << "\nNome do aluno: ";
    getline(cin, nome);

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].nome == nome) {

            cout << "\nNova nota 1: ";
            cin >> alunos[i].nota1;

            cout << "Nova nota 2: ";
            cin >> alunos[i].nota2;

            cout << "Nova nota 3: ";
            cin >> alunos[i].nota3;

            alunos[i].media =
                calcularMedia(
                    alunos[i].nota1,
                    alunos[i].nota2,
                    alunos[i].nota3
                );

            cout << "\nNotas atualizadas!\n";
            return;
        }
    }

    cout << "\nAluno nao encontrado.\n";
}

void removerAluno() {

    string nome;

    cin.ignore();

    cout << "\nNome do aluno: ";
    getline(cin, nome);

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].nome == nome) {

            for (int j = i; j < quantidade - 1; j++) {
                alunos[j] = alunos[j + 1];
            }

            quantidade--;

            cout << "\nAluno removido!\n";
            return;
        }
    }

    cout << "\nAluno nao encontrado.\n";
}

void aprovados() {

    cout << "\n===== APROVADOS =====\n";

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].media >= 7) {

            cout << alunos[i].nome
                << " - "
                << alunos[i].media
                << endl;
        }
    }
}

void reprovados() {

    cout << "\n===== REPROVADOS =====\n";

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].media < 7) {

            cout << alunos[i].nome
                << " - "
                << alunos[i].media
                << endl;
        }
    }
}

void mediaTurma() {

    if (quantidade == 0) {
        cout << "\nSem alunos cadastrados.\n";
        return;
    }

    float soma = 0;

    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].media;
    }

    cout << "\nMedia da turma: "
        << soma / quantidade
        << endl;
}

void ranking() {

    if (quantidade == 0) {
        return;
    }

    Aluno copia[MAX_ALUNOS];

    for (int i = 0; i < quantidade; i++) {
        copia[i] = alunos[i];
    }

    for (int i = 0; i < quantidade - 1; i++) {

        for (int j = i + 1; j < quantidade; j++) {

            if (copia[j].media >
                copia[i].media) {

                Aluno temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    cout << "\n===== RANKING =====\n";

    for (int i = 0; i < quantidade; i++) {

        cout << i + 1
            << "º - "
            << copia[i].nome
            << " ("
            << copia[i].media
            << ")\n";
    }
}

void boletim() {

    string nome;

    cin.ignore();

    cout << "\nNome do aluno: ";
    getline(cin, nome);

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].nome == nome) {

            cout << "\n===== BOLETIM =====\n";

            cout << "Nome: "
                << alunos[i].nome
                << endl;

            cout << "Nota 1: "
                << alunos[i].nota1
                << endl;

            cout << "Nota 2: "
                << alunos[i].nota2
                << endl;

            cout << "Nota 3: "
                << alunos[i].nota3
                << endl;

            cout << "Media: "
                << alunos[i].media
                << endl;

            if (alunos[i].media >= 7)
                cout << "APROVADO\n";
            else
                cout << "REPROVADO\n";

            return;
        }
    }

    cout << "\nAluno nao encontrado.\n";
}

int main() {

    int opcao;

    do {

        cout << "\n=========================\n";
        cout << " SISTEMA ESCOLAR\n";
        cout << "=========================\n";
        cout << "1 - Cadastrar Aluno\n";
        cout << "2 - Listar Alunos\n";
        cout << "3 - Buscar Aluno\n";
        cout << "4 - Editar Notas\n";
        cout << "5 - Remover Aluno\n";
        cout << "6 - Aprovados\n";
        cout << "7 - Reprovados\n";
        cout << "8 - Media da Turma\n";
        cout << "9 - Ranking\n";
        cout << "10 - Boletim\n";
        cout << "0 - Sair\n";

        cout << "\nOpcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1: cadastrarAluno(); break;
        case 2: listarAlunos(); break;
        case 3: buscarAluno(); break;
        case 4: editarNotas(); break;
        case 5: removerAluno(); break;
        case 6: aprovados(); break;
        case 7: reprovados(); break;
        case 8: mediaTurma(); break;
        case 9: ranking(); break;
        case 10: boletim(); break;
        case 0: cout << "\nEncerrando...\n"; break;
        default: cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}