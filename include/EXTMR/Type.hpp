#ifndef EXTMR_TYPE_HPP
#define EXTMR_TYPE_HPP

namespace extmr{

class TypeRegister;
class Method;

/**
 * Holds information about a registered type for the reflection mechanism.
 * 
 * The type can be a primitive (\a Primitive), a pointer (\a Pointer),
 * an array (\a Array), a reflected class (\a Class) or a template instance
 * (\a CompClass). Each one of these type categories is identified by the
 * internal enum Category.
 * Except for the a\ Primitive each one of the others categories is 
 * implemented in a subclass.
 * This class should be instantiate only when registering a type by
 * the TypeRegister.
 */
class Type
{
public:
    
    /**
     * Enum of supported type categories.
     */
    enum Category
    {
        /**
         * A primitive type.
         */
        Primitive = 1,
        
        /**
         * A pointer to another supported type.
         */
        Pointer = 2,
        
        /**
         * An array of another supported type.
         */
        Array = 4,
        
        /**
         * A reflected class.
         */
        Class = 8,
        
        /**
         *  A type that depends on other types, i.e. a template instance.
         */
        CompoundClass = 24,
    };
    
    /**
     * Basic constructor for initialization.
     * 
     * @param name The type name.
     */
    Type(const std::string& name = "");
    
    /**
     * Basic constructor for initialization.
     * 
     * @param cppType The type_info struct of the type.
     */
    Type(const std::type_info& cppType);
    
    /**
     * Ask if the type is instantiable.
     * 
     * @return True if the type is instatiable.
     */
    bool isInstatiable();
    
    /**
     * Ask if the type is copyable.
     * 
     * @return True if the type is copyable.
     */
    bool isCopyable();
    
    /**
     * Ask if the type can be assigned to.
     * 
     * @return True if the type can be assigned to.
     */
    bool isLvalue();
    
    /**
     * Construct a new instance of the type.
     * 
     * @param addres If not NULL the placement constructor is called to this
     * address.
     * @return The pointer to the new instance.
     */
    void* newInstance(void* address = NULL) const;
    
    /**
     * Copy an instance of the type.
     * 
     * @param originAddr The address of the instance to be copied.
     * @param destAddr If not NULL the placement copy constructor is called to
     * this address.
     * @return The pointer of the new copied instance.
     */
    void* copyInstance(void* originAddr, void* destAddr = NULL) const;
    
    /**
     * Destroy an instance of the type.
     * 
     * @param address The pointer to the instance to be deleted.
     * @param dallocate If true the delete operator is called causing the memory to be deallocated otherwise the
     * destructor is called explicity.
     */
    void deleteInstance(void* address, bool deallocate = true) const;
    
    /**
     * Perfor an assignment between two object instances of this type.
     * 
     * @param lvalueAddr A pointer to an object of this type to be used as lvalue.
     * @param rvalueAddr A pointer to an object of this type to be used as rvalue.
     */
    void assignInstance(void* lvalueAddr, const void* rvalueAddr) const;
    
    /**
     * Get a value of Category that represent the type category.
     * 
     * @return The type category of this type.
     */
    Category getCategory() const;
    
    /**
     * Get the name of this type.
     * 
     * @return The name of the type. 
     */
    const std::string& getName() const;
    
    /**
     * Get the size of this type, the same of the one given by sizeof().
     * 
     * @return The type size.
     */
    std::size_t getSize() const;
    
    /**
     * Get the type_info struct of this type,
     * the same of the one given by the typeid().
     * 
     * @return The type_info struct.
     */
    const std::type_info& getCppType() const;
    
    /**
     * Get the Type of the type pointed by this one.
     * If the type is not a pointer then a NULL reference is returned.
     * 
     * @return The pointed Type.
     */
    const Type& getPointedType() const;
    
    /**
     * Get the Type of the array elemets.
     * If the type is not an array then a NULL reference is returned.
     * 
     * @return The element Type.
     */
    const Type& getArrayElementType() const;
    
    /**
     * Get the size of the array.
     * If the type is not an array then 0 is returned.
     * 
     * @return The type size.
     */
    const std::size_t getArraySize() const;
    
    /**
     * Ask if the property is of a numerical type.
     * 
     * @return true if the property is of a numerical type.
     */
    // TODO: this method is not yet implemented. Decide whether and how to implement this method.
    bool isNumerical() const;
    
    virtual ~Type();
    
    /**
     * Non valid Type.
     * This Type can be used where ever a reference to a non valid Type is
     * needed.
     */
    static const Type Void;
    
protected:
    
    /**
     * Constructor for full initialization.
     * 
     * @param name The type name.
     * @param size The type size.
     * @param cppType The type_info struct of the type.
     * @param constructor The type constructor wrapper function.
     * @param copyConstructor The type copy constructor wrapper function.
     * @param destructor The type destructor wrapper function.
     * @param operatorAssign The type assign operator wrapper function.
     * @param relatedType The Type of the type pointed by this 
     * one or the array element type of this one depending of the next parameter.
     * @param isArray If true relatedType is the array element type, otherwise is the pointed type.
     * @param arraySize The size of the array.
     */
    Type
    (
            const std::string& name,
            std::size_t size,
            const std::type_info& cppType,
            Constructor* constructor,
            CopyConstructor* copyConstructor,
            Destructor* destructor,
            AssignOperator* assignOperator,
            const Type& relatedType = Type::Void,
            bool isArray = false,
            std::size_t arraySize = 0
     );
    
    // The name of the type.
    std::string name_;

    // The size of the type.
    size_t size_;
    
    // The type_info struct of the type.
    const std::type_info& cppType_;
    
    // The type category.
    Category category_;
    
    // The constructor function object.
    Constructor* constructor_;
    
    // The copy constructor function object.
    CopyConstructor* copyConstructor_;
    
    // The destructor function object.
    Destructor* destructor_;
    
    // The assign operator function object.
    AssignOperator* assignOperator_;
    
    // A pointer to the Type object of the type pointed by this one or the one
    // this type is an array of.
    const Type* relatedType_;
    
    // The size of the array.
    size_t arraySize_;
    
    // The type register is the factory for the type class and need to access
    // the private constructor.
    friend class TypeRegister;
    
    // The equal operator must be a friend to access the cppType field.
    friend bool operator==(const Type&, const Type&);
    
    // The not equal operator must be a friend to access the cppType field.
    friend bool operator!=(const Type&, const Type&);
    
    // The less operator must be a friend to access the cppType field.
    friend bool operator<(const Type&, const Type&);
};

bool inline operator==(const Type& t1, const Type& t2)
{
    return t1.cppType_ == t2.cppType_;
}

bool inline operator!=(const Type& t1, const Type& t2)
{
    return t1.cppType_ != t2.cppType_;
}

// type less operator compares the type_info struct with the type_info::before() method.
bool inline operator<(const Type& t1, const Type& t2)
{
    return t1.cppType_.before(t2.cppType_);
}

typedef std::set<const Type*, PtrCmpByVal<Type> > ConstTypeSetById;
typedef std::set<Type*, PtrCmpByVal<Type> > TypeSetById;
typedef std::set<const Type*, PtrCmpByName<Type> > ConstTypeSetByName;
typedef std::set<Type*, PtrCmpByName<Type> > TypeSetByName;
typedef std::vector<const Type*> ConstTypeVector;
typedef std::vector<Type*> TypeVector;

} // namespace extmr

#endif // EXTMR_TYPE_HPP