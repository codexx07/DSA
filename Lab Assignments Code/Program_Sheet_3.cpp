#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Song {
    string title;
    string artist;
    string album;
};

void insertion_sort_songs_Question1(vector<Song>& songs, string key) {
    if (key == "title") {
        for (int i = 1; i < songs.size(); i++) {
        Song current_song = songs[i];
        int j = i - 1;
        while (j >= 0 && songs[j].title > current_song.title) {
            songs[j + 1] = songs[j];
            j--;
        }
        songs[j + 1] = current_song;
        }
    } else if (key == "artist") {
        for (int i = 1; i < songs.size(); i++) {
        Song current_song = songs[i];
        int j = i - 1;
        while (j >= 0 && songs[j].artist > current_song.artist) {
            songs[j + 1] = songs[j];
            j--;
        }
        songs[j + 1] = current_song;
        }
    } else if (key == "album") {
        for (int i = 1; i < songs.size(); i++) {
        Song current_song = songs[i];
        int j = i - 1;
        while (j >= 0 && songs[j].album > current_song.album) {
            songs[j + 1] = songs[j];
            j--;
        }
        songs[j + 1] = current_song;
        }
    }
}

void Question1() {
    vector<Song> playlist = {
        {"Thriller", "Michael Jackson", "Thriller"},
        {"Imagine", "John Lennon", "Imagine"},
        {"Bohemian Rhapsody", "Queen", "A Night at the Opera"},
        {"Hotel California", "Eagles", "Hotel California"},
        {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV"}
    };


    cout << "Sorted By Artist:" << endl;
    insertion_sort_songs_Question1(playlist, "artist");
    for (Song song : playlist) {
        cout << "\"" << song.title << "\" by " << song.artist << endl;
    }

    cout << endl << "Sorted By Song Title:" << endl;
    insertion_sort_songs_Question1(playlist, "title");
    for (Song song : playlist) {
        cout << "\"" << song.title << "\" by " << song.artist << endl;
    }
}

class Respondent {
public:
    string name;
    int age;
    string gender;

    Respondent(string name, int age, string gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
};

void swap(vector<Respondent>& data, int a, int b) {
    Respondent temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void selection_sort_Question2(vector<Respondent>& data) {
    for (int i = 0; i < data.size(); i++) {
        int min_index = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[min_index].age > data[j].age) {
                min_index = j;
            }
        }
        swap(data, i, min_index);
    }
}

int Question2() {
    vector<Respondent> data = {
        Respondent("John", 25, "Male"),
        Respondent("Mary", 32, "Female"),
        Respondent("Alex", 19, "Male"),
        Respondent("Jane", 27, "Female"),
        Respondent("Mark", 21, "Male")
    };

    selection_sort_Question2(data);
    cout << "Name" << "\t" << "Age" << "\t" << "Gender" << endl;
    for (Respondent r : data) {
        cout << r.name << "\t" << r.age << "\t" << r.gender << endl;
    }
}

class Student {
public:
    string name;
    int grade;
    int age;

    Student(string name, int grade, int age) {
        this->name = name;
        this->grade = grade;
        this->age = age;
    }
};

void bubble_sort_Question3(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].grade > students[j + 1].grade) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void Question3() {
    vector<Student> students = {
        Student("John", 75, 20),
        Student("Mary", 90, 22),
        Student("Alex", 60, 19),
        Student("Jane", 80, 21),
        Student("Mark", 85, 20)
    };

    bubble_sort_Question3(students);
    cout << "Name" << "\t" << "Grade" << "\t" << "Age" << endl;
    for (Student student : students) {
        cout << student.name << "\t" << student.grade << "\t" << student.age << endl;
    }
}

int main() {
    // Question1();
    // Question2();
    Question3();
}