////////////////////////////////////////////////////////////////////////////////
//
// B L I N K
//
// Copyright (C) 2016-2018 Blink Mobile Shell Project
//
// This file is part of Blink.
//
// Blink is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Blink is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Blink. If not, see <http://www.gnu.org/licenses/>.
//
// In addition, Blink is also subject to certain additional terms under
// GNU GPL version 3 section 7.
//
// You should have received a copy of these additional terms immediately
// following the terms and conditions of the GNU General Public License
// which accompanied the Blink Source Code. If not, see
// <http://www.github.com/blinksh/blink>.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef TermJS_h
#define TermJS_h

NSString *_encodeString(NSString *str)
{
  NSData *jsonData = [NSJSONSerialization dataWithJSONObject:@[ str ] options:0 error:nil];
  return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
}

NSString *term_init()
{
  return @"term_init();";
}

NSString *term_write(NSString *data) {
  return [NSString stringWithFormat:@"term_write(%@[0]);", _encodeString(data)];
}

NSString *term_clear()
{
  return @"term_clear();";
}

NSString *term_reset()
{
  return @"term_reset();";
}

NSString *term_focus()
{
  return @"term_focus();";
}

NSString *term_blur()
{
  return @"term_blur();";
}

NSString *term_setWidth(NSInteger count)
{
  return [NSString stringWithFormat:@"term_setWidth(\"%ld\");", (long)count];
}

NSString *term_increaseFontSize()
{
  return @"term_increaseFontSize();";
}

NSString *term_decreaseFontSize()
{
  return @"term_decreaseFontSize();";
}

NSString *term_resetFontSize()
{
  return @"term_resetFontSize();";
}

NSString *term_scale(CGFloat scale)
{
  return [NSString stringWithFormat:@"term_scale(%f);", scale];
}

NSString *term_setFontSize(NSNumber *newSize)
{
  return [NSString stringWithFormat:@"term_setFontSize(\"%@\");", newSize];
}

NSString *term_getCurrentSelection()
{
  return @"term_getCurrentSelection();";
}

NSString *term_setCursorBlink(BOOL state)
{
  return [NSString stringWithFormat:@"term_set('cursor-blink', %@)", state ? @"true" : @"false"];
}

NSString *term_setBoldAsBright(BOOL state)
{
  return [NSString stringWithFormat:@"term_set('enable-bold-as-bright', %@)", state ? @"true" : @"false"];
}

NSString *term_setBoldEnabled(NSUInteger state)
{
  NSString *stateStr = @"null";
  if (state == 1) {
    stateStr = @"true";
  } else if (state == 2) {
    stateStr = @"false";
  }
  return [NSString stringWithFormat:@"term_set('enable-bold', %@)", stateStr];
}

NSString *term_setFontFamily(NSString *family)
{
  return [NSString stringWithFormat:@"term_setFontFamily(%@[0]);", _encodeString(family)];
}

NSString *term_appendUserCss(NSString *css)
{
  return [NSString stringWithFormat:@"term_appendUserCss(%@[0])", _encodeString(css)];
}

NSString *term_cleanSelection()
{
  return @"term_cleanSelection();";
}

NSString *term_modifySelection(NSString *direction, NSString *granularity)
{
  return [NSString stringWithFormat:@"term_modifySelection(%@[0], %@[0])", _encodeString(direction), _encodeString(granularity)];
}

NSString *term_modifySideSelection()
{
  return @"term_modifySideSelection();";
}


#endif /* TermJS_h */
