void AFunction()
{
    // This function does not return normally, 
    // instead execution will resume at a catch block.
    // The thrown object is in this case of the type char const*,
    // i.e. it is a C-style string. More usually, exception
    // objects are of class type.
    throw "This is an exception!"; 
}

void AnotherFunction()
{
    // To catch exceptions, you first have to introduce
    // a try block via " try { ... } ". Then multiple catch
    // blocks can follow the try block.
    // " try { ... } catch(type 1) { ... } catch(type 2) { ... }"
    try 
    {
        AFunction();
       // Because the function throws an exception,
       // the rest of the code in this block will not
       // be executed
    }
    catch(char const* pch)  // This catch block 
                            // will react on exceptions
                            // of type char const*
    {
        // Execution will resume here.
        // You can handle the exception here.
    }
               // As can be seen
    catch(...) // The ellipsis indicates that this
               // block will catch exceptions of any type. 
    {
       // In this example, this block will not be executed,
       // because the preceding catch block is chosen to 
       // handle the exception.
    }
}

