// Andrea M. Stojanovski
// Lab 6 (4 Extra Credit)

#include <iostream>

using namespace std;

// PART 4

struct Movie {
    string name;
    int rating;
    int watched;
};

bool add_movie(Movie* movies) {
int count = 0;
  int name;
  // counting empty spots
  for (Movie* p = movies; p<movies.size(); ++p)
  {
      if (p->name == 0)
      {
          count++;
      }
  }
  for (Movie* p = movies; p<movies+5; ++p)
  {
      // check availability
      if(count >= 1)
      {
          cout<<"Enter movie title: ";
          cin>>name;
      }
      else
      {
          cout<<"Array is full.";
          return false;
      }
      // check uniqueness
      while(p->Name == name)
      {
          cout<<"Enter an unique title.";
          cin>>name;
      }
      // input info
      p->Name = name;
      cout<<"Enter name: "; cin>>p->name;
      cout<<"Enter rating: "; cin>>p->rating;
  }
  cout<<"New movie added successfully"<<endl;
  return true;
}

void add_viewing(Movie* movies, string name) {
  for (Movie* p = movies; p<movies.size(); ++p){
      if (p->name) // found movie, no watch it
      {
          p->watched += 1;
      }
  }
}

void show_movies() {
  for (Movie* p = movies; p<movies.size(); ++p){
      if (p->name) // found movie, no watch it
      {
          cout << movie.name();
      }
  }
}

int main() {
  // PART 4
  cout << "PART 4" << endl;

  vector<Movie> myMovies;

  cin >> name;
}