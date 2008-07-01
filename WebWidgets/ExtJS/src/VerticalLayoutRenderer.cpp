//
// VerticalLayoutRenderer.cpp
//
// $Id: //poco/Main/WebWidgets/ExtJS/src/VerticalLayoutRenderer.cpp#2 $
//
// Library: ExtJS
// Package: Core
// Module:  VerticalLayoutRenderer
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


#include "Poco/WebWidgets/ExtJS/VerticalLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/Utility.h"
#include "Poco/WebWidgets/VerticalLayout.h"
#include <sstream>


namespace Poco {
namespace WebWidgets {
namespace ExtJS {


VerticalLayoutRenderer::VerticalLayoutRenderer()
{
}


VerticalLayoutRenderer::~VerticalLayoutRenderer()
{
}


void VerticalLayoutRenderer::renderHead(const Renderable* pRenderable, const RenderContext& context, std::ostream& ostr)
{
	poco_assert_dbg (pRenderable != 0);
	poco_assert_dbg (pRenderable->type() == typeid(Poco::WebWidgets::VerticalLayout));
	const VerticalLayout* pLayout = static_cast<const Poco::WebWidgets::VerticalLayout*>(pRenderable);

	int padVal = pLayout->getPadding();
	std::string padding;
	if (padVal > 0)
	{
		std::ostringstream pad;
		// or style=\"background:#deecfd;padding-left:10px\"
		// or transparent gif: <img src=\"resources/images/default/s.gif\" width=\"10\" height=\"1\" alt=\"\">'
		pad << "<p style=\"padding-top:" << padVal << "px\">&nbsp;</p>";
		padding = pad.str();
	}
	// a vertical layout is a table with one column
	std::string layoutConfig("{columns:1}");
	std::string layout("table");
	LayoutRenderer::renderLayoutHead(pLayout, context, ostr, layout, layoutConfig, 1, padding);
}


} } } // namespace Poco::WebWidgets::ExtJS
