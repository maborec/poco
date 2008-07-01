//
// HorizontalLayout.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/HorizontalLayout.h#2 $
//
// Library: WebWidgets
// Package: Layouts
// Module:  HorizontalLayout
//
// Definition of the HorizontalLayout class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
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


#ifndef WebWidgets_HorizontalLayout_INCLUDED
#define WebWidgets_HorizontalLayout_INCLUDED


#include "Poco/WebWidgets/Layout.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API HorizontalLayout: public Layout
	/// HorizontalLayout arranges views sequentially
{
public:
	typedef Poco::AutoPtr<HorizontalLayout> Ptr;

	HorizontalLayout(int pad=0);
		/// Creates the HorizontalLayout.

	int getPadding() const;
		/// Returns the padding value, a value <= 0 means no padding which is the default.
		
	void setPadding(int pad);
		/// Sets the padding value, a value <= 0 means no padding which is the default.
		
protected:
	~HorizontalLayout();
		/// Destroys the HorizontalLayout.
		
private:
	int _padding;
};


inline int HorizontalLayout::getPadding() const
{
	return _padding;
}
		
		
inline void HorizontalLayout::setPadding(int pad)
{
	_padding = pad;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_HorizontalLayout_INCLUDED
