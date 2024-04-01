#include <iostream>

class Base {
public:
    int publicMember;

protected:
    int protectedMember;

private:
    int privateMember;
};

class DerivedPublic : public Base {
public:
    void accessBaseMembers() {
        publicMember = 1;        // 可访问基类的public成员
        protectedMember = 2;    // 可访问基类的protected成员
        // privateMember = 3;    // 错误！不能访问基类的private成员
    }
};

class DerivedProtected : protected Base {
public:
    void accessBaseMembers() {
        publicMember = 1;        // 可访问基类的protected成员
        protectedMember = 2;    // 可访问基类的protected成员
        // privateMember = 3;    // 错误！不能访问基类的private成员
    }
};

class DerivedPrivate : private Base {
public:
    void accessBaseMembers() {
        publicMember = 1;        // 可访问基类的private成员
        protectedMember = 2;    // 可访问基类的private成员
        // privateMember = 3;    // 错误！不能访问基类的private成员
    }
};

int main() {
    DerivedPublic derivedPublic;
    derivedPublic.publicMember = 1;    // 可访问基类的public成员
    // derivedPublic.protectedMember = 2;  // 错误！不能访问基类的protected成员
    // derivedPublic.privateMember = 3;    // 错误！不能访问基类的private成员

    DerivedProtected derivedProtected;
    // derivedProtected.publicMember = 1;    // 错误！不能访问基类的protected成员
    // derivedProtected.protectedMember = 2;  // 错误！不能访问基类的protected成员
    // derivedProtected.privateMember = 3;    // 错误！不能访问基类的private成员

    DerivedPrivate derivedPrivate;
    // derivedPrivate.publicMember = 1;    // 错误！不能访问基类的private成员
    // derivedPrivate.protectedMember = 2;  // 错误！不能访问基类的private成员
    // derivedPrivate.privateMember = 3;    // 错误！不能访问基类的private成员

    return 0;
}