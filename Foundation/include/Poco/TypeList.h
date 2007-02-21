//
// TypeList.h
//
// $Id: //poco/1.3/Foundation/include/Poco/TypeList.h#1 $
//
// Library: Foundation
// Package: Core
// Module:  TypeList
//
// Implementation of the TypeList template.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Portions extracted and adapted from
// The Loki Library
// Copyright (c) 2001 by Andrei Alexandrescu
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef  Foundation_TypeList_INCLUDED
#define  Foundation_TypeList_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/MetaProgramming.h"


namespace Poco {


template <class Head, class Tail> 
struct TypeList;

	
struct NullTypeList
{
	enum
	{
		length = 0
	};

	bool operator == (const NullTypeList&) const
	{
		return true;
	}

	bool operator != (const NullTypeList&) const
	{
		return false;
	}

	bool operator < (const NullTypeList&) const
	{
		return false;
	}
};


template <class Head, class Tail> 
struct TypeList
	/// Compile Time List of Types
{
	typedef Head HeadType;
	typedef Tail TailType;
	typedef typename TypeWrapper<HeadType>::CONSTTYPE ConstHeadType;
	typedef typename TypeWrapper<TailType>::CONSTTYPE ConstTailType;
	enum
	{
		length = TailType::length+1
	};

	TypeList():head(), tail()
	{
	}

	TypeList(ConstHeadType& h, ConstTailType& t):head(h), tail(t)
	{
	}

	TypeList(const TypeList& tl): head(tl.head), tail(tl.tail)
	{
	}

	TypeList& operator = (const TypeList& tl)
	{
		if (this != &tl)
		{
			TypeList tmp(tl);
			swap(tmp);
		}
		return *this;
	}

	bool operator == (const TypeList& tl) const
	{
		return tl.head == head && tl.tail == tail;
	}

	bool operator != (const TypeList& tl) const
	{
		return !(*this == tl);
	}

	bool operator < (const TypeList& tl) const
	{
		bool smaller = (head < tl.head);
		if (smaller)
			return smaller;
		return tail < tl.tail;
	}

	void swap(TypeList& tl)
	{
		std::swap(head, tl.head);
		std::swap(tail, tl.tail);
	}
	
	HeadType head;
	TailType tail;
};


#define POCO_TYPELIST_1(T0) TypeList<T0, NullTypeList>
#define POCO_TYPELIST_2(T0, T1) TypeList<T0, POCO_TYPELIST_1(T1) >
#define POCO_TYPELIST_3(T0, T1, T2) TypeList<T0, POCO_TYPELIST_2(T1, T2) >
#define POCO_TYPELIST_4(T0, T1, T2, T3) TypeList<T0, POCO_TYPELIST_3(T1, T2, T3) >
#define POCO_TYPELIST_5(T0, T1, T2, T3, T4) TypeList<T0, POCO_TYPELIST_4(T1, T2, T3, T4) >
#define POCO_TYPELIST_6(T0, T1, T2, T3, T4, T5) TypeList<T0, POCO_TYPELIST_5(T1, T2, T3, T4, T5) >
#define POCO_TYPELIST_7(T0, T1, T2, T3, T4, T5, T6) TypeList<T0, POCO_TYPELIST_6(T1, T2, T3, T4, T5, T6) >
#define POCO_TYPELIST_8(T0, T1, T2, T3, T4, T5, T6, T7) TypeList<T0, POCO_TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) >
#define POCO_TYPELIST_9(T0, T1, T2, T3, T4, T5, T6, T7, T8) TypeList<T0, POCO_TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) >
#define POCO_TYPELIST_10(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9) \
	TypeList<T0, POCO_TYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) >
#define POCO_TYPELIST_11(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) \
	TypeList<T0, POCO_TYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) >
#define POCO_TYPELIST_12(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) \
	TypeList<T0, POCO_TYPELIST_11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) >
#define POCO_TYPELIST_13(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) \
	TypeList<T0, POCO_TYPELIST_12(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) >
#define POCO_TYPELIST_14(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) \
	TypeList<T0, POCO_TYPELIST_13(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) >
#define POCO_TYPELIST_15(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) \
	TypeList<T0, POCO_TYPELIST_14(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) >
#define POCO_TYPELIST_16(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) \
	TypeList<T0, POCO_TYPELIST_15(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) >
#define POCO_TYPELIST_17(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) \
	TypeList<T0, POCO_TYPELIST_16(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) >
#define POCO_TYPELIST_18(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17) \
	TypeList<T0, POCO_TYPELIST_17(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17) >
#define POCO_TYPELIST_19(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18) \
	TypeList<T0, POCO_TYPELIST_18(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18) >
#define POCO_TYPELIST_20(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) \
	TypeList<T0, POCO_TYPELIST_19(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) >


template <typename T0  = NullTypeList, 
	typename T1  = NullTypeList, 
	typename T2  = NullTypeList,
    typename T3  = NullTypeList, 
	typename T4  = NullTypeList, 
	typename T5  = NullTypeList,
    typename T6  = NullTypeList, 
	typename T7  = NullTypeList, 
	typename T8  = NullTypeList,
    typename T9  = NullTypeList, 
	typename T10 = NullTypeList, 
	typename T11 = NullTypeList,
    typename T12 = NullTypeList, 
	typename T13 = NullTypeList, 
	typename T14 = NullTypeList,
    typename T15 = NullTypeList, 
	typename T16 = NullTypeList, 
	typename T17 = NullTypeList,
	typename T18 = NullTypeList,
	typename T19 = NullTypeList> 
struct TypeListType
	/// TypeListType takes 1 - 20 typename arguments.
	/// Usage:
	///
	/// TypeListType<T0, T1, ... , Tn>::HeadType typeList;
	///
	/// typeList is a TypeList of T0, T1, ... , Tn
{
private:
    typedef typename TypeListType<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19>::HeadType TailType;

public:
    typedef TypeList<T0, TailType> HeadType;
};


template<>
struct TypeListType<>
{
    typedef NullTypeList HeadType;
};


template<int n> 
struct Getter
{
	template<class Ret, class Head, class Tail>
	inline static Ret& get(TypeList<Head, Tail>& val)
	{
		return Getter<n-1>::template get<Ret, typename Tail::HeadType, typename Tail::TailType>(val.tail);
	}

	template<class Ret, class Head, class Tail>
	inline static const Ret& get(const TypeList<Head, Tail>& val)
	{
		return Getter<n-1>::template get<Ret, typename Tail::HeadType, typename Tail::TailType>(val.tail);
	}
};


template<> 
struct Getter<0>
{
	template<class Ret, class Head, class Tail>
	inline static Ret& get(TypeList<Head, Tail>& val)
	{
		return val.head;
	}

	template<class Ret, class Head, class Tail>
	inline static const Ret& get(const TypeList<Head, Tail>& val)
	{
		return val.head;
	}
};

template <int N, class Head> 
struct TypeGetter;


template <int N, class Head, class Tail> 
struct TypeGetter<N, TypeList<Head, Tail> >
{
	typedef typename TypeGetter<N-1, Tail>::HeadType HeadType;
	typedef typename TypeWrapper<HeadType>::CONSTTYPE ConstHeadType;
};


template <class Head, class Tail> 
struct TypeGetter<0, TypeList<Head, Tail> >
{
	typedef typename TypeList<Head, Tail>::HeadType HeadType;
	typedef typename TypeWrapper<HeadType>::CONSTTYPE ConstHeadType;
};


template <class Head, class T>
struct TypeLocator;
	/// TypeLocator returns the first occurrence of the type T in Head
	/// or -1 if the type is not found.
	///
	/// Usage example:
	///
	/// TypeLocator<Head, int>::HeadType TypeLoc;
	///
	/// if (2 == TypeLoc.value) ...
	///
	

template <class T>
struct TypeLocator<NullTypeList, T>
{
	enum { value = -1 };
};


template <class T, class Tail>
struct TypeLocator<TypeList<T, Tail>, T>
{
	enum { value = 0 };
};


template <class Head, class Tail, class T>
struct TypeLocator<TypeList<Head, Tail>, T>
{
private:
	enum { tmp = TypeLocator<Tail, T>::value };
public:
	enum { value = tmp == -1 ? -1 : 1 + tmp };
};


template <class Head, class T> 
struct TypeAppender;
	/// TypeAppender appends T (type or a TypeList) to Head.
	///
	/// Usage:
	///
	/// typedef TypeListType<char>::HeadType Type1;
	/// typedef TypeAppender<Type1, int>::HeadType Type2;
	/// (Type2 is a TypeList of char,int)
	///
	///	typedef TypeListType<float, double>::HeadType Type3;
	/// typedef TypeAppender<Type2, Type3>::HeadType Type4;
	/// (Type4 is a TypeList of char,int,float,double)
	///

template<>
struct TypeAppender<NullTypeList, NullTypeList>
{
	typedef NullTypeList HeadType;
};


template<class T>
struct TypeAppender<NullTypeList, T>
{
	typedef POCO_TYPELIST_1(T) HeadType;
};


template<class Head, class Tail>
struct TypeAppender<NullTypeList, TypeList<Head, Tail> >
{
	typedef TypeList<Head, Tail> HeadType;
};


template<class Head, class Tail, class T>
struct TypeAppender<TypeList<Head, Tail>, T>
{
	typedef TypeList<Head, typename TypeAppender<Tail, T>::HeadType> HeadType;
};


template <class Head, class T> 
struct TypeOneEraser;
	/// TypeOneEraser erases the first occurence of the type T in Head.
	/// Usage:
	///
	/// typedef TypeListType<char, int, float>::HeadType Type3;
	/// typedef TypeOneEraser<Type3, int>::HeadType Type2;
	/// (Type2 is a TypeList of char,float)
	///


template <class T>
struct TypeOneEraser<NullTypeList, T>
{
	typedef NullTypeList HeadType;
};


template <class T, class Tail>
struct TypeOneEraser<TypeList<T, Tail>, T>
{
	typedef Tail HeadType;
};


template <class Head, class Tail, class T>
struct TypeOneEraser<TypeList<Head, Tail>, T>
{
	typedef TypeList <Head, typename TypeOneEraser<Tail, T>::HeadType> HeadType;
};


template <class Head, class T> 
struct TypeAllEraser;
	/// TypeAllEraser erases all the occurences of the type T in Head.
	/// Usage:
	///
	/// typedef TypeListType<char, int, float, int>::HeadType Type4;
	/// typedef TypeAllEraser<Type4, int>::HeadType Type2;
	/// (Type2 is a TypeList of char,float)
	///


template <class T>
struct TypeAllEraser<NullTypeList, T>
{
	typedef NullTypeList HeadType;
};


template <class T, class Tail>
struct TypeAllEraser<TypeList<T, Tail>, T>
{
	typedef typename TypeAllEraser<Tail, T>::HeadType HeadType;
};


template <class Head, class Tail, class T>
struct TypeAllEraser<TypeList<Head, Tail>, T>
{
	typedef TypeList <Head, typename TypeAllEraser<Tail, T>::HeadType> HeadType;
};


template <class Head> 
struct TypeDuplicateEraser;
	/// TypeDuplicateEraser erases all but the first occurence of the type T in Head.
	/// Usage:
	///
	/// typedef TypeListType<char, int, float, int>::HeadType Type4;
	/// typedef TypeDuplicateEraser<Type4, int>::HeadType Type3;
	/// (Type3 is a TypeList of char,int,float)
	///


template <> 
struct TypeDuplicateEraser<NullTypeList>
{
	typedef NullTypeList HeadType;
};


template <class Head, class Tail>
struct TypeDuplicateEraser<TypeList<Head, Tail> >
{
private:
	typedef typename TypeDuplicateEraser<Tail>::HeadType L1;
	typedef typename TypeOneEraser<L1, Head>::HeadType L2;
public:
	typedef TypeList<Head, L2> HeadType;
};


template <class Head, class T, class R>
struct TypeOneReplacer;
	/// TypeOneReplacer replaces the first occurence 
	/// of the type T in Head with type R.
	/// Usage:
	///
	/// typedef TypeListType<char, int, float, int>::HeadType Type4;
	/// typedef TypeOneReplacer<Type4, int, double>::HeadType TypeR;
	/// (TypeR is a TypeList of char,double,float,int)
	///

template <class T, class R>
struct TypeOneReplacer<NullTypeList, T, R>
{
	typedef NullTypeList HeadType;
};


template <class T, class Tail, class R>
struct TypeOneReplacer<TypeList<T, Tail>, T, R>
{
	typedef TypeList<R, Tail> HeadType;
};


template <class Head, class Tail, class T, class R>
struct TypeOneReplacer<TypeList<Head, Tail>, T, R>
{
	typedef TypeList<Head, typename TypeOneReplacer<Tail, T, R>::HeadType> HeadType;
};


template <class Head, class T, class R>
struct TypeAllReplacer;
	/// TypeAllReplacer replaces all the occurences 
	/// of the type T in Head with type R.
	/// Usage:
	///
	/// typedef TypeListType<char, int, float, int>::HeadType Type4;
	/// typedef TypeAllReplacer<Type4, int, double>::HeadType TypeR;
	/// (TypeR is a TypeList of char,double,float,double)
	///


template <class T, class R>
struct TypeAllReplacer<NullTypeList, T, R>
{
	typedef NullTypeList HeadType;
};


template <class T, class Tail, class R>
struct TypeAllReplacer<TypeList<T, Tail>, T, R>
{
	typedef TypeList<R, typename TypeAllReplacer<Tail, T, R>::HeadType> HeadType;
};


template <class Head, class Tail, class T, class R>
struct TypeAllReplacer<TypeList<Head, Tail>, T, R>
{
	typedef TypeList<Head, typename TypeAllReplacer<Tail, T, R>::HeadType> HeadType;
};


} // namespace Poco


#endif
