//
// GridLayout.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/GridLayout.h#5 $
//
// Library: WebWidgets
// Package: Layouts
// Module:  GridLayout
//
// Definition of the GridLayout class.
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


#ifndef WebWidgets_GridLayout_INCLUDED
#define WebWidgets_GridLayout_INCLUDED


#include "Poco/WebWidgets/Layout.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API GridLayout: public Layout
	/// GridLayout manages views in a grid
{
public:
	typedef Poco::AutoPtr<GridLayout> Ptr;

	GridLayout(std::size_t colCnt, std::size_t rowCnt=0);
		/// Creates the GridLayout. colCnt must be greater zero, rowCnt can be greater than zero. 
		/// A rowCnt of zero indicates autosize.

	void add(View::Ptr pView);
		/// Adds a View right after the last set view.

	View::Ptr get(std::size_t rowCnt, std::size_t colCnt) const;
		/// Returns the view at the given position

	void set(View::Ptr pView, std::size_t rowCnt, std::size_t colCnt);
		/// Sets the view at the given position. 

	std::size_t columns() const;
		/// returns the number of columns

	std::size_t rows() const;
		/// Returns the current number of rows

	std::size_t maxRows() const;
		/// Returns the maximum number of allowed rows, 0 means infinite

	void minimize();
		/// Minimizes the rowCount (i.e. empty lines at the end of the grid are truncated
		
	void setHorizontalPadding(int hor);
		/// Sets horizontal padding. A value <= 0 means no padding which is also the default.
		
	void setVerticalPadding(int vert);
		/// Sets vertical padding. A value <= 0 means no padding which is also the default.	
		
	int getHorizontalPadding() const;
		/// Gets horizontal padding. A value <= 0 means no padding which is also the default.
		
	int getVerticalPadding() const;
		/// Gets vertical padding. A value <= 0 means no padding which is also the default.		

protected:
	~GridLayout();
		/// Destroys the GridLayout.

	std::size_t pos(std::size_t rowCnt, std::size_t colCnt) const;
		/// Maps a 2D coordinate to the position inside the vector

	void resize(std::size_t rowCnt);
		/// Resizes the layout to store at least rowCnt rows

private:
	const std::size_t _colCnt;
	const std::size_t _rowCnt;
	int _horPadding;
	int _vertPadding;
	std::size_t _lastIdx;
};


//
// inlines
//

inline std::size_t GridLayout::pos(std::size_t rowCnt, std::size_t colCnt) const
{
	poco_assert_dbg(colCnt < _colCnt);
	return rowCnt*_colCnt+colCnt;
}


inline std::size_t GridLayout::columns() const
{
	return _colCnt;
}


inline std::size_t GridLayout::rows() const
{
	return (size()+_colCnt-1) /columns();
}


inline std::size_t GridLayout::maxRows() const
{
	return _rowCnt;
}


inline void GridLayout::add(View::Ptr pView)
{
	set(pView, _lastIdx/_colCnt, _lastIdx%_colCnt);
}


inline void GridLayout::setHorizontalPadding(int hor)
{
	_horPadding = hor;
}

		
inline void GridLayout::setVerticalPadding(int vert)
{
	_vertPadding = vert;
}

		
inline int GridLayout::getHorizontalPadding() const
{
	return _horPadding;
}

		
inline int GridLayout::getVerticalPadding() const
{
	return _vertPadding;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_GridLayout_INCLUDED
