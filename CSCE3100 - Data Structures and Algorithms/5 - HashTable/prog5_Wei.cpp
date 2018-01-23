/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 3110
Instructor: Robert Renka
Date: 11/16




                        CSCE 3110  Program #5


        Due date:  Thursday, November 16, 2017


        Write a program that computes the number of collisions encountered
        in a sequence of insertions into a probing hash table (Figures
        5.14--5.17, 5.22) for each of the three probing strategies discussed
        in the textbook.  This requires modification of findPos (Figure 5.16).

        Hashed objects will be 4-digit integers (0 to 9999).  Use a table
        size large enough that the hash function is just h(x) = x.

        The test program should consist of a loop on the following operations:
           Prompt the user for an integer N with N=0 as a termination flag
           For each of the three strategies {linear, quadratic, double}
              Initialize a hash table of integers
              Generate and insert a random sequence of N 4-digit integers
              Print the number of collisions


        Your program should be implemented in a single file named
        prog5_Name.cpp, where Name is your last name, and submitted
        via Blackboard.


*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

template <typename HashedObj>
class HashTable
{
  public:
    int getCollisions() const {
      return collisions;
    }
    bool isPrime(int n) {
      for(int i = 3; i < static_cast<int>(sqrt(n) + 1); i+=2) {
        if(n % i == 0) {
          return false;
        }
      }
      return true;
    }

    int nextPrime(int n) {
      while(!isPrime(n++)) {
        ;
      }
      return n;
    }

    bool contains( const HashedObj & x ) const
      { return isActive( findPos( x ) ); }

    bool insert( const HashedObj & x , string s)
    {
      // Insert x as active
        int currentPos = findPos( x );

        if(s == "linear") {
          currentPos = findLinearPos( x );
        } else if (s == "quadratic") {
          currentPos = findQuadPos( x );
        } else if (s == "double") {
          currentPos = findDoublePos( x );
        } else {
          return false;
        }

        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = HashEntry( x, ACTIVE );

            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }
    enum EntryType { ACTIVE, EMPTY, DELETED };


    explicit HashTable( int size = 101 ) : array( nextPrime( size )), collisions(0)
      { makeEmpty( ); }

    void makeEmpty( )
    {
        currentSize = 0;
        for( int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
    }

  private:
    struct HashEntry
    {
         HashedObj element;
         EntryType info;

         HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
           : element( e ), info( i ) { }
    };

    vector<HashEntry> array;
    int currentSize, collisions;

    int findPos( const HashedObj & x )
    {
        int offset = 1;
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            currentPos += offset;  // Compute ith probe
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    int findLinearPos( const HashedObj & x )
    {
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            cout << "collision with linear probing at " << currentPos << endl;
            collisions++;
            currentPos++;  // Compute ith probe
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    int findQuadPos( const HashedObj & x )
    {
        int offset = 1;
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            cout << "collision with quadratic probing at " << currentPos << endl;
            collisions++;
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    int findDoublePos( const HashedObj & x )
    {
        int offset = myhash( x );
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            cout << "collision with double probing at " << currentPos << endl;
            collisions++;
            currentPos += offset;  // Compute ith probe
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }


    /**
     * Rehashing for quadratic probing hash table.
     */
    void rehash( )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
                insert( oldArray[ i ].element , "quadratic");
    }

    /**
     * Rehashing for separate chaining hash table.

    void rehash( )
    {
        vector<list<HashedObj> > oldLists = theLists;

            // Create new double-sized, empty table
        theLists.resize( nextPrime( 2 * theLists.size( ) ) );
        for( int j = 0; j < theLists.size( ); j++ )
            theLists[ j ].clear( );

            // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldLists.size( ); i++ )
        {
            list<HashedObj>::iterator itr = oldLists[ i ].begin( );
            while( itr != oldLists[ i ].end( ) )
                insert( *itr++ );
        }
    }*/

    int myhash( const HashedObj & x ) const {
      return x % array.size();
    }
};



int main() {

  HashTable<int> linear_probing(1007);
  HashTable<int> quad_probing(1007);
  HashTable<int> double_probing(1007);

  int n = 1;
  while (n) {
    cout << "How many numbers would you like to insert? (0 to quit)" << endl;
    cin >> n;
    if(cin.fail()) {
      cin.clear();
      cin.ignore(100, '\n');
      n = 1;
      continue;
    }

    for(int i = 0; i < n; i++) {
      int x = rand() % 10000;
      linear_probing.insert(x, "linear");
      quad_probing.insert(x, "quadratic");
      double_probing.insert(x, "double");
    }
    cout << "Number of collisions with linear probing " << linear_probing.getCollisions() << endl;
    cout << "Number of collisions with quadratic probing " << quad_probing.getCollisions() << endl;
    cout << "Number of collisions with double probing " << double_probing.getCollisions() << endl;
  }

  return 0;
}
