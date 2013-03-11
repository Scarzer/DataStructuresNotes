// Implementation of Statisticain Class
// Homework Assignment Number 1
// Provided by Irving Derin

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "stats.h"

namespace main_savitch_2C{

    statistician::statistician(){
        // Constructer. There are no pre-conditions needed here. 
        // All we are doing is creating this class, giving it a length of 0
        // I am not initializing ANY othe of the variables for a reason
        // But there might be some benifit to set up the total as zero....
        // Will look deeper into this!

        count = 0; 
        total = 0;
    }

    int statistician::length( ) const{
        // Return the length of the class. Make sure that the lenght actually
        // exists before you attempt to return it! 
        // This is a getter function. It will not perform any changes!
    
        return count ;
    }

    void statistician::next(double r){
        // Very important function! This will be the public interface for 
        // the class. It will accept a number as a parameter. It will than
        // check it against the current 'largest', 'tinyest' (<-- weird spelling).
        // After that is complete, and it has modified whatever it needs to modify.
        // 
        // It will than be applied to total, and finally incrememnt length by 1.
        // This is a boid function so I ain't returnin' nothin

        if(count < 1){

        // If there was nothing made before. Set everything to r 
        tinyest = r;
        largest = r;
        }
        
        if ( r > largest ){
            largest = r;
        }

        else if( r < tinyest){
            tinyest = r;
        }
        
        total += r;

        count++; //increase the count
    }

    void statistician::reset( ){
        // Resets the statistician object to have absolutely nothing inside of it
        // That means set total, tinyest, largest, and count to zero. 
        //
        // As an optimization, check to see that the object has length > 0, otherwise
        // just return the bloody thing back!
        if(count < 1){
            return;
        }

        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;

        }

    

    double statistician::sum() const{
        // Return the value "total"
        if ( count < 1){
            return 0;
        }

        return total;
    }

    double statistician::mean() const{
        // Return a double of the function (sum / total)
        // DEFINETELY MAKE A CHECK TO SEE THAT COUNT > 0!!!!!
        assert (count > 0);
        return total/count;
    }
        
    double statistician::minimum() const{
        // Return the value for minimum. 
        // Make sure that count > 0, otherwise value is undefined!
        assert (count > 0);
        return tinyest;
    }

    double statistician::maximum() const{
        // Return the value for the Maximum.
        // Make sure that the count > 0, unless we decide to make
        // the max value 0. But as of right now it's not like that!!
        assert ( count > 0);
        return largest;
    }

    statistician operator *(double scale, const statistician& s1){
        
        if (s1.length() == 0) return statistician();
        
        statistician s = statistician();
        s.count = s1.count;
        s.total = s1.total * scale;
        
        // If the scale is positive, everything is fine. If it's negative, the largest and the smallest must switch!
        if (scale > 0){
            s.largest = s1.largest * scale;
            s.tinyest = s1.tinyest * scale;
        }
        else{
            s.largest = s1.tinyest * scale;
            s.tinyest = s1.largest * scale;
        }
        
        return s;
    }

    statistician operator +(const statistician& s1, const statistician& s2){
        
     
      if (s1.length() ==0){
         return statistician(s2);
         }
      
      else if (s2.length() ==0){
        return statistician(s1); 
      }
        statistician s = statistician();

        s.count = s1.count + s2.count;
        s.total = s1.total + s2.total;
      
      // Killing to birds here by checking if one is smaller or equal
      if(s1.tinyest < s2.tinyest || s1.tinyest == s2.tinyest){
            s.tinyest = s1.tinyest;
        }
        else{
            s.tinyest = s2.tinyest;
        }

      // Same story, but doing it with the largest
        if(s1.largest < s2.largest || s1.largest == s2.largest){
            s.largest = s2.largest;
        }
        else{
            s.largest = s1.largest;
        }


        return s;
    }

    bool operator == (const statistician& s1, const statistician& s2){
        
        // If they's both empty, just ship them out like that
        if( ( s1.length() == 0) && (s2.length() == 0) ) return true;

        // Go through anything that could be different. If they are, it's all false!
        if( !(s1.length() == s2.length() ) ) return false;
        else if( !(s1.sum() == s2.sum() ) ) return false;
        else if( !(s1.minimum() == s2.minimum() ) ) return false;
        else if( !(s1.maximum() == s2.maximum() ) ) return false;
        else if( !(s1.mean() == s2.mean() ) ) return false;
 
        return true;
    }


}



