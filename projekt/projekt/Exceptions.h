/**
 * @file Exceptions.h
 * @brief The file contains three classes which are thrown as exceptions when the need arises.
 * @author Oliwia Mlonek
 */
#pragma once
#include <iostream>
#include <exception>


 /**
  * @class IsNull
  * @brief Responsible for throwing a message when the used list is empty.
  */
class IsNull : virtual public std::exception {

protected:

    std::string error_message = "You did not upload any photo!!!";  ///< Error message

public:

    /**
      * Create the IsNull object.
      */
    explicit
        IsNull() 
    {}


    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~IsNull() throw () {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. 
     */
    virtual const char* what() const throw () {
        return error_message.c_str();
    }


};



/**
 * @class IsOneElementOnly
 * @brief Responsible for throwing a message when the used list has only one element.
 */
class IsOneElementOnly : virtual public std::exception {

protected:

    std::string error_message = "Nothing more to undo!";      ///< Error message

public:

    /**
      * Create the IsOneElementOnly object.
      */
    explicit
        IsOneElementOnly()
    {}


    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~IsOneElementOnly() throw () {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*.
     */
    virtual const char* what() const throw () {
        return error_message.c_str();
    }


};

/**
 * @class NoFaceFound                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
 * @brief Responsible for throwing a message when face detector cannot recognize any face.
 */
class NoFaceFound : virtual public std::exception {

protected:

    std::string error_message = "No face was detected!";      ///< Error message

public:

    /**
   * Create the IsOneElementOnly object.
   */
    explicit
        NoFaceFound()
    {}


    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~NoFaceFound() throw () {}

    /** Returns a pointer to the (constant) error description.
    *  @return A pointer to a const char*.
    */
    virtual const char* what() const throw () {
        return error_message.c_str();
    }


};