    /*
    Written by Irving Derin and Asad Kamal
     
    To keep ourselves on track. We should remind ourselves what it
    is that we are doing right here right now. This is a sequence
    class that keeps track of a bunch of numbers that we feed it with
    a limit on how much it can take. Which means that we have a constraint
    on the number of things we can put in. That has already beenpreset to
    30. That's fine.
     
    In addition to that, based on the functions that we have:
    "start"
    "advance"
    "insert"
    "attach"
    "remove_current"
    "size"
    "current"
    "is_item"
     
    these are just ways of interacting with the class that we have.
     
    --> the "start" method is setting the current value to the first one in the array.
     
    --> the "advance" method sets the current method to the next one. Before we're allowed to do that
    we need to check to see that a next element exists. Otherwise we're at the end of the class
     
    --> the "insert" method is inserting another item into the sequence class.
    We need to make sure that the number of elements in the class isn't greater than the capacity of the class.
     
    --> Keep a size interger inside that will keep track of the number of elements that we have inside the container class
     
    --> Keep a location interger to maintain the position of where we are. Like a pointer!
     
    --> Use the pointer to return what we have inside the array at the moment.
    */
     
     
    #include <stdlib.h>
    #include <assert.h>
    #include <stdio.h>
    #include "sequence1.h"
    #include <cstdlib>
     
    namespace main_savitch_3
       {
     
         
        typedef double value_type;
        typedef size_t size_type;
       
        static const size_type CAPACITY = 30;
         
     
        sequence::sequence () {
                     
            // sequence initialized as empty sequence
            m_currLoc = 0;
            m_currSize = 0;
            m_itemTruth = false;
        }
     
     
        void sequence::start()  {
         
            // first item in the sequence becomes the current item
            // if empty then no current item
            if(m_currSize < 1){
                m_itemTruth = false;
            }
     
            else{
                m_itemTruth = true;
            }
            m_currLoc = 0;
     
            }
     
     
        void sequence::advance() {
            // Precondition: is_item returns true.
            // Postcondition: If the current item was already the last item in the
            // sequence, then there is no longer any current item. Otherwise, the new
            // current item is the item immediately after the original current item.
     
            assert(m_itemTruth);
            if(m_currSize <= m_currLoc + 1){
                m_itemTruth = false;
            }
     
            else{
                m_currLoc++;
            }
     
           
           
            }
     
       void sequence::insert(const value_type& entry){  
            // Precondition: size( ) < CAPACITY.
            // Postcondition: A new copy of entry has been inserted in the sequence
            // before the current item. If there was no current item, then the new entry
            // has been inserted at the front of the sequence. In either case, the newly
            // inserted item is now the current item of the sequence.        
            // This function is ALLOWED to set itemTruth to true!
           
            assert( m_currSize < CAPACITY);
            if( !m_itemTruth ){                        
                m_currLoc = 0;
            }
            m_currSize++;
     
            for(size_type i = m_currSize; i > m_currLoc; i--){
                sq[i] = sq[i-1];
            }
     
            sq[m_currLoc] = entry;
            m_itemTruth = true;
        }
     
       void sequence::attach(const value_type& entry) {
            // Precondition: size( ) < CAPACITY.
            // Postcondition: A new copy of entry has been inserted in the sequence after
            // the current item. If there was no current item, then the new entry has
            // been attached to the end of the sequence. In either case, the newly
            // inserted item is now the current item of the sequence.
            // Precondition: size( ) < CAPACITY
            //
            // This function is only ALLOWED to set itemTruth to true!
     
            assert( m_currSize < CAPACITY);
            if( !m_itemTruth ){                        
                m_currLoc = m_currSize;
                sq[m_currLoc] = entry;
                m_currSize++;
            }
     
            else{
                m_currSize++;
                m_currLoc++;
                for(size_type i = m_currSize; i > m_currLoc; i--){
                    sq[i] = sq[i-1];
                }
                sq[m_currLoc] = entry;
            }
     
            m_itemTruth = true;
        }
     
       void sequence::remove_current() {
            // Precondition: is_item returns true.
            // Postcondition: The current item has been removed from the sequence, and the
            // item after this (if there is one) is now the new current item.
            //
            // This function is allowed to only set itemTruth to FALSE!
     
            assert( m_itemTruth );
            for( size_type i = m_currLoc; i < m_currSize; i++){
                sq[i] = sq[i+1];
            }
            m_currSize--;
            if( m_currSize <= m_currLoc){
                m_itemTruth = false;
     
            }
        }
     
     
       bool sequence::is_item() const {
        // bool is_item( ) const
        // Postcondition: A true return value indicates that there is a valid
        // "current" item that may be retrieved by activating the current
        // member function (listed below). A false return value indicates that
        // there is no valid current item.
     
           return m_itemTruth;
        }
     
        size_type sequence::size( ) const {
            //This also works (Cause i'm an idiot if it didn't work)
     
            return m_currSize;
        }
     
        value_type sequence::current() const {
            // This totally works
     
            return sq[m_currLoc];
        }
     
       
     
    }
