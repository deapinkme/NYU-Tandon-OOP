//
//  main.cpp
//  classes
//
//  Created by Dennis Fenchenko on 6/2/21.
//  Copyright © 2021 Dennis Fenchenko. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Movie {
    string name;
    int rating;
    int watched;
};

bool add_movie(vector<Movie> &movies, string name, int rating, int watched) {
    for (Movie movie : movies) {
        if (movie.name == name) {
            cout << "The movie already exists" << endl;
            return false;
        }
    }
    struct Movie new_movie {name, rating, watched};
    movies.push_back(new_movie);
    return true;
}

bool add_viewing(vector<Movie> &movies, string name) {
    for (Movie &movie : movies) {
    if (movie.name == name) {
        movie.watched++;
        return true;
}
    }
    cout << "Movie with the given name doesn't exist" << endl;
    return false;
}

void display_movies(const vector<Movie> &movies)  {
    for (Movie movie : movies) {
        cout << "The movie is " << movie.name << endl;
        cout << "It has a rating of " << movie.rating << endl;
        cout << "It was watched " << movie.watched << " times" << endl;
        cout << endl;
    }
}



int main(int argc, const char * argv[]) {
    vector <Movie> movies; 
    add_movie(movies, "Thor", 8, 4);
    add_movie(movies, "Iron Man", 5, 12);
    display_movies(movies);
    add_viewing(movies, "Thor");
    display_movies(movies);
    return 0;
}

/*
helpful link:

http://www.cplusplus.com/forum/general/207136/'

*/