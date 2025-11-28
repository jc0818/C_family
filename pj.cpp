#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// 태그 클래스
class Tag {
private:
    string name;
public:
    Tag(string n = "") : name(n) {}
    ~Tag() {}

    string getName() const { return name; }
    void setName(string n) { name = n; }
};

// 메모 클래스
class Note {
private:
    string title;
    string content;
    vector<Tag> tags;
    bool favorite;
    time_t timestamp;

public:
    Note(string t = "", string c = "") : title(t), content(c), favorite(false) {
        timestamp = time(0);
    }

    ~Note() {
        tags.clear();
    }

    // Getter
    string getTitle() const { return title; }
    string getContent() const { return content; }
    bool isFavorite() const { return favorite; }
    time_t getTimestamp() const { return timestamp; }

    // Setter
    void setTitle(string t) { title = t; }
    void setContent(string c) { content = c; }
    void toggleFavorite() { favorite = !favorite; }

    // 태그 관리
    void addTag(string tagName) {
        tags.push_back(Tag(tagName));
    }

    void removeTag(int index) {
        if (index >= 0 && index < tags.size()) {
            tags.erase(tags.begin() + index);
        }
    }

    vector<Tag> getTags() const { return tags; }

    bool hasTag(string tagName) const {
        for (int i = 0; i < tags.size(); i++) {
            if (tags[i].getName() == tagName) return true;
        }
        return false;
    }

    void display() const {
        cout << "\n=== " << title << " ===" << endl;
        cout << "내용: " << content << endl;
        cout << "즐겨찾기: " << (favorite ? "★" : "☆") << endl;
        cout << "태그: ";
        for (int i = 0; i < tags.size(); i++) {
            cout << "#" << tags[i].getName() << " ";
        }
        cout << endl;
    }
};

// TODO 항목 클래스
class TodoItem {
private:
    string description;
    bool completed;

public:
    TodoItem(string desc = "") : description(desc), completed(false) {}
    ~TodoItem() {}

    string getDescription() const { return description; }
    bool isCompleted() const { return completed; }

    void setDescription(string desc) { description = desc; }
    void toggleComplete() { completed = !completed; }
};

// TODO 리스트 클래스
class TodoList {
private:
    string title;
    vector<TodoItem> items;

public:
    TodoList(string t = "") : title(t) {}

    ~TodoList() {
        items.clear();
    }

    string getTitle() const { return title; }
    void setTitle(string t) { title = t; }

    void addItem(string desc) {
        items.push_back(TodoItem(desc));
    }

    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    void toggleItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].toggleComplete();
        }
    }

    vector<TodoItem> getItems() const { return items; }

    void display() const {
        cout << "\n=== TODO: " << title << " ===" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". ";
            if (items[i].isCompleted()) {
                cout << "[✓] ";
            }
            else {
                cout << "[ ] ";
            }
            cout << items[i].getDescription() << endl;
        }
    }
};

// 사용자 클래스
class User {
private:
    string username;
    string password;
    vector<Note> notes;
    vector<TodoList> todoLists;

public:
    User(string u = "", string p = "") : username(u), password(p) {}

    ~User() {
        notes.clear();
        todoLists.clear();
    }

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    bool checkPassword(string p) const { return password == p; }

    // 메모 관리
    void addNote(Note note) {
        notes.push_back(note);
    }

    void removeNote(int index) {
        if (index >= 0 && index < notes.size()) {
            notes.erase(notes.begin() + index);
        }
    }

    Note* getNote(int index) {
        if (index >= 0 && index < notes.size()) {
            return &notes[index];
        }
        return NULL;
    }

    vector<Note> getNotes() const { return notes; }

    vector<Note> searchNotesByTitle(string keyword) const {
        vector<Note> results;
        for (int i = 0; i < notes.size(); i++) {
            if (notes[i].getTitle().find(keyword) != string::npos) {
                results.push_back(notes[i]);
            }
        }
        return results;
    }

    vector<Note> searchNotesByTag(string tag) const {
        vector<Note> results;
        for (int i = 0; i < notes.size(); i++) {
            if (notes[i].hasTag(tag)) {
                results.push_back(notes[i]);
            }
        }
        return results;
    }

    vector<Note> getFavoriteNotes() const {
        vector<Note> results;
        for (int i = 0; i < notes.size(); i++) {
            if (notes[i].isFavorite()) {
                results.push_back(notes[i]);
            }
        }
        return results;
    }

    // TODO 리스트 관리
    void addTodoList(TodoList todo) {
        todoLists.push_back(todo);
    }

    void removeTodoList(int index) {
        if (index >= 0 && index < todoLists.size()) {
            todoLists.erase(todoLists.begin() + index);
        }
    }

    TodoList* getTodoList(int index) {
        if (index >= 0 && index < todoLists.size()) {
            return &todoLists[index];
        }
        return NULL;
    }

    vector<TodoList> getTodoLists() const { return todoLists; }

    // 파일 저장/불러오기
    void saveToFile() const {
        string filename = username + "_data.txt";
        ofstream file(filename.c_str());

        if (!file.is_open()) {
            cout << "파일 저장 실패!" << endl;
            return;
        }

        // 메모 저장
        file << notes.size() << endl;
        for (int i = 0; i < notes.size(); i++) {
            file << notes[i].getTitle() << endl;
            file << notes[i].getContent() << endl;
            file << notes[i].isFavorite() << endl;

            vector<Tag> tags = notes[i].getTags();
            file << tags.size() << endl;
            for (int j = 0; j < tags.size(); j++) {
                file << tags[j].getName() << endl;
            }
        }

        // TODO 리스트 저장
        file << todoLists.size() << endl;
        for (int i = 0; i < todoLists.size(); i++) {
            file << todoLists[i].getTitle() << endl;

            vector<TodoItem> items = todoLists[i].getItems();
            file << items.size() << endl;
            for (int j = 0; j < items.size(); j++) {
                file << items[j].getDescription() << endl;
                file << items[j].isCompleted() << endl;
            }
        }

        file.close();
        cout << "데이터 저장 완료!" << endl;
    }

    void loadFromFile() {
        string filename = username + "_data.txt";
        ifstream file(filename.c_str());

        if (!file.is_open()) {
            cout << "불러올 데이터가 없습니다." << endl;
            return;
        }

        notes.clear();
        todoLists.clear();

        // 메모 불러오기
        int noteCount;
        file >> noteCount;
        file.ignore();

        for (int i = 0; i < noteCount; i++) {
            string title, content;
            bool favorite;

            getline(file, title);
            getline(file, content);
            file >> favorite;

            Note note(title, content);
            if (favorite) note.toggleFavorite();

            int tagCount;
            file >> tagCount;
            file.ignore();

            for (int j = 0; j < tagCount; j++) {
                string tagName;
                getline(file, tagName);
                note.addTag(tagName);
            }

            notes.push_back(note);
        }

        // TODO 리스트 불러오기
        int todoCount;
        file >> todoCount;
        file.ignore();

        for (int i = 0; i < todoCount; i++) {
            string title;
            getline(file, title);

            TodoList todo(title);

            int itemCount;
            file >> itemCount;
            file.ignore();

            for (int j = 0; j < itemCount; j++) {
                string desc;
                bool completed;

                getline(file, desc);
                file >> completed;
                file.ignore();

                todo.addItem(desc);
                if (completed) {
                    todo.toggleItem(j);
                }
            }

            todoLists.push_back(todo);
        }

        file.close();
        cout << "데이터 불러오기 완료!" << endl;
    }
};

// 시스템 클래스
class NoteSystem {
private:
    vector<User> users;
    User* currentUser;

    void registerUser() {
        string username, password;
        cout << "\n=== 회원가입 ===" << endl;
        cout << "사용자명: ";
        cin >> username;
        cout << "비밀번호: ";
        cin >> password;

        users.push_back(User(username, password));
        cout << "회원가입 완료!" << endl;
    }

    bool login() {
        string username, password;
        cout << "\n=== 로그인 ===" << endl;
        cout << "사용자명: ";
        cin >> username;
        cout << "비밀번호: ";
        cin >> password;

        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username && users[i].checkPassword(password)) {
                currentUser = &users[i];
                currentUser->loadFromFile();
                cout << "로그인 성공!" << endl;
                return true;
            }
        }

        cout << "로그인 실패!" << endl;
        return false;
    }

    void manageNotes() {
        while (true) {
            cout << "\n=== 메모 관리 ===" << endl;
            cout << "1. 새 메모 작성" << endl;
            cout << "2. 메모 목록 보기" << endl;
            cout << "3. 메모 검색 (제목)" << endl;
            cout << "4. 메모 검색 (태그)" << endl;
            cout << "5. 즐겨찾기 보기" << endl;
            cout << "6. 메모 수정" << endl;
            cout << "7. 메모 삭제" << endl;
            cout << "0. 돌아가기" << endl;
            cout << "선택: ";

            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 0) break;

            switch (choice) {
            case 1: {
                string title, content;
                cout << "제목: ";
                getline(cin, title);
                cout << "내용: ";
                getline(cin, content);

                Note note(title, content);

                cout << "태그 추가 (입력 완료시 'q' 입력): " << endl;
                while (true) {
                    string tag;
                    cout << "태그: ";
                    getline(cin, tag);
                    if (tag == "q") break;
                    note.addTag(tag);
                }

                currentUser->addNote(note);
                cout << "메모 저장 완료!" << endl;
                break;
            }
            case 2: {
                vector<Note> notes = currentUser->getNotes();
                for (int i = 0; i < notes.size(); i++) {
                    cout << "\n[" << i + 1 << "]";
                    notes[i].display();
                }
                break;
            }
            case 3: {
                string keyword;
                cout << "검색 키워드: ";
                getline(cin, keyword);

                vector<Note> results = currentUser->searchNotesByTitle(keyword);
                cout << "\n검색 결과: " << results.size() << "개" << endl;
                for (int i = 0; i < results.size(); i++) {
                    results[i].display();
                }
                break;
            }
            case 4: {
                string tag;
                cout << "태그명: ";
                getline(cin, tag);

                vector<Note> results = currentUser->searchNotesByTag(tag);
                cout << "\n검색 결과: " << results.size() << "개" << endl;
                for (int i = 0; i < results.size(); i++) {
                    results[i].display();
                }
                break;
            }
            case 5: {
                vector<Note> favorites = currentUser->getFavoriteNotes();
                cout << "\n즐겨찾기: " << favorites.size() << "개" << endl;
                for (int i = 0; i < favorites.size(); i++) {
                    favorites[i].display();
                }
                break;
            }
            case 6: {
                int index;
                cout << "수정할 메모 번호: ";
                cin >> index;
                cin.ignore();

                Note* note = currentUser->getNote(index - 1);
                if (note != NULL) {
                    cout << "1. 내용 수정\n2. 즐겨찾기 토글\n3. 태그 추가\n선택: ";
                    int option;
                    cin >> option;
                    cin.ignore();

                    if (option == 1) {
                        string content;
                        cout << "새 내용: ";
                        getline(cin, content);
                        note->setContent(content);
                    }
                    else if (option == 2) {
                        note->toggleFavorite();
                        cout << "즐겨찾기 변경 완료!" << endl;
                    }
                    else if (option == 3) {
                        string tag;
                        cout << "추가할 태그: ";
                        getline(cin, tag);
                        note->addTag(tag);
                    }
                }
                break;
            }
            case 7: {
                int index;
                cout << "삭제할 메모 번호: ";
                cin >> index;
                currentUser->removeNote(index - 1);
                cout << "삭제 완료!" << endl;
                break;
            }
            }
        }
    }

    void manageTodos() {
        while (true) {
            cout << "\n=== TODO 관리 ===" << endl;
            cout << "1. 새 TODO 리스트 생성" << endl;
            cout << "2. TODO 리스트 보기" << endl;
            cout << "3. TODO 항목 추가" << endl;
            cout << "4. TODO 완료 체크" << endl;
            cout << "5. TODO 항목 삭제" << endl;
            cout << "6. TODO 리스트 삭제" << endl;
            cout << "0. 돌아가기" << endl;
            cout << "선택: ";

            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 0) break;

            switch (choice) {
            case 1: {
                string title;
                cout << "TODO 리스트 제목: ";
                getline(cin, title);
                currentUser->addTodoList(TodoList(title));
                cout << "생성 완료!" << endl;
                break;
            }
            case 2: {
                vector<TodoList> todos = currentUser->getTodoLists();
                for (int i = 0; i < todos.size(); i++) {
                    cout << "\n[" << i + 1 << "]";
                    todos[i].display();
                }
                break;
            }
            case 3: {
                int index;
                cout << "TODO 리스트 번호: ";
                cin >> index;
                cin.ignore();

                TodoList* todo = currentUser->getTodoList(index - 1);
                if (todo != NULL) {
                    string desc;
                    cout << "TODO 항목: ";
                    getline(cin, desc);
                    todo->addItem(desc);
                    cout << "추가 완료!" << endl;
                }
                break;
            }
            case 4: {
                int listIdx, itemIdx;
                cout << "TODO 리스트 번호: ";
                cin >> listIdx;
                cout << "항목 번호: ";
                cin >> itemIdx;

                TodoList* todo = currentUser->getTodoList(listIdx - 1);
                if (todo != NULL) {
                    todo->toggleItem(itemIdx - 1);
                    cout << "체크 완료!" << endl;
                }
                break;
            }
            case 5: {
                int listIdx, itemIdx;
                cout << "TODO 리스트 번호: ";
                cin >> listIdx;
                cout << "항목 번호: ";
                cin >> itemIdx;

                TodoList* todo = currentUser->getTodoList(listIdx - 1);
                if (todo != NULL) {
                    todo->removeItem(itemIdx - 1);
                    cout << "삭제 완료!" << endl;
                }
                break;
            }
            case 6: {
                int index;
                cout << "삭제할 TODO 리스트 번호: ";
                cin >> index;
                currentUser->removeTodoList(index - 1);
                cout << "삭제 완료!" << endl;
                break;
            }
            }
        }
    }

    void saveUsers() {
        ofstream file("users.txt");
        if (!file.is_open()) return;

        file << users.size() << endl;
        for (int i = 0; i < users.size(); i++) {
            file << users[i].getUsername() << endl;
            file << users[i].getPassword() << endl;
        }
        file.close();
    }

    void loadUsers() {
        ifstream file("users.txt");
        if (!file.is_open()) return;

        int userCount;
        file >> userCount;
        file.ignore();

        users.clear();
        for (int i = 0; i < userCount; i++) {
            string username, password;
            getline(file, username);
            getline(file, password);
            users.push_back(User(username, password));
        }
        file.close();
    }

public:
    NoteSystem() : currentUser(NULL) {
        loadUsers();
    }

    ~NoteSystem() {
        saveUsers();
        users.clear();
    }

    void run() {
        while (true) {
            if (currentUser == NULL) {
                cout << "\n=== 메모장 & TODO 시스템 ===" << endl;
                cout << "1. 회원가입" << endl;
                cout << "2. 로그인" << endl;
                cout << "0. 종료" << endl;
                cout << "선택: ";

                int choice;
                cin >> choice;

                if (choice == 0) break;
                else if (choice == 1) registerUser();
                else if (choice == 2) login();
            }
            else {
                cout << "\n=== 메인 메뉴 ===" << endl;
                cout << "사용자: " << currentUser->getUsername() << endl;
                cout << "1. 메모 관리" << endl;
                cout << "2. TODO 관리" << endl;
                cout << "3. 데이터 저장" << endl;
                cout << "4. 로그아웃" << endl;
                cout << "0. 종료" << endl;
                cout << "선택: ";

                int choice;
                cin >> choice;

                if (choice == 0) {
                    currentUser->saveToFile();
                    break;
                }
                else if (choice == 1) manageNotes();
                else if (choice == 2) manageTodos();
                else if (choice == 3) currentUser->saveToFile();
                else if (choice == 4) {
                    currentUser->saveToFile();
                    currentUser = NULL;
                    cout << "로그아웃 완료!" << endl;
                }
            }
        }

        cout << "\n프로그램을 종료합니다." << endl;
    }
};

int main() {
    NoteSystem system;
    system.run();
    return 0;
}
