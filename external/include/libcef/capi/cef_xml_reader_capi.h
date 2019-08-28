// Copyright (c) 2019 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=984dbef3999ba44fc3c963053cba9e3fb2ff1625$
//

#ifndef CEF_INCLUDE_CAPI_CEF_XML_READER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_XML_READER_CAPI_H_
#pragma once

#include "cef_base_capi.h"
#include "cef_stream_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Structure that supports the reading of XML data via the libxml streaming API.
// The functions of this structure should only be called on the thread that
// creates the object.
///
typedef struct _cef_xml_reader_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Moves the cursor to the next node in the document. This function must be
  // called at least once to set the current cursor position. Returns true (1)
  // if the cursor position was set successfully.
  ///
  int(CEF_CALLBACK* move_to_next_node)(struct _cef_xml_reader_t* self);

  ///
  // Close the document. This should be called directly to ensure that cleanup
  // occurs on the correct thread.
  ///
  int(CEF_CALLBACK* close)(struct _cef_xml_reader_t* self);

  ///
  // Returns true (1) if an error has been reported by the XML parser.
  ///
  int(CEF_CALLBACK* has_error)(struct _cef_xml_reader_t* self);

  ///
  // Returns the error string.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_error)(
      struct _cef_xml_reader_t* self);

  // The below functions retrieve data for the node at the current cursor
  // position.

  ///
  // Returns the node type.
  ///
  cef_xml_node_type_t(CEF_CALLBACK* get_type)(struct _cef_xml_reader_t* self);

  ///
  // Returns the node depth. Depth starts at 0 for the root node.
  ///
  int(CEF_CALLBACK* get_depth)(struct _cef_xml_reader_t* self);

  ///
  // Returns the local name. See http://www.w3.org/TR/REC-xml-names/#NT-
  // LocalPart for additional details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_local_name)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns the namespace prefix. See http://www.w3.org/TR/REC-xml-names/ for
  // additional details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_prefix)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns the qualified name, equal to (Prefix:)LocalName. See
  // http://www.w3.org/TR/REC-xml-names/#ns-qualnames for additional details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_qualified_name)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns the URI defining the namespace associated with the node. See
  // http://www.w3.org/TR/REC-xml-names/ for additional details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_namespace_uri)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns the base URI of the node. See http://www.w3.org/TR/xmlbase/ for
  // additional details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_base_uri)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns the xml:lang scope within which the node resides. See
  // http://www.w3.org/TR/REC-xml/#sec-lang-tag for additional details.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_xml_lang)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns true (1) if the node represents an NULL element. <a/> is considered
  // NULL but <a></a> is not.
  ///
  int(CEF_CALLBACK* is_empty_element)(struct _cef_xml_reader_t* self);

  ///
  // Returns true (1) if the node has a text value.
  ///
  int(CEF_CALLBACK* has_value)(struct _cef_xml_reader_t* self);

  ///
  // Returns the text value.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_value)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns true (1) if the node has attributes.
  ///
  int(CEF_CALLBACK* has_attributes)(struct _cef_xml_reader_t* self);

  ///
  // Returns the number of attributes.
  ///
  size_t(CEF_CALLBACK* get_attribute_count)(struct _cef_xml_reader_t* self);

  ///
  // Returns the value of the attribute at the specified 0-based index.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_attribute_byindex)(
      struct _cef_xml_reader_t* self,
      int index);

  ///
  // Returns the value of the attribute with the specified qualified name.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_attribute_byqname)(
      struct _cef_xml_reader_t* self,
      const cef_string_t* qualifiedName);

  ///
  // Returns the value of the attribute with the specified local name and
  // namespace URI.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_attribute_bylname)(
      struct _cef_xml_reader_t* self,
      const cef_string_t* localName,
      const cef_string_t* namespaceURI);

  ///
  // Returns an XML representation of the current node's children.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_inner_xml)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns an XML representation of the current node including its children.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_outer_xml)(
      struct _cef_xml_reader_t* self);

  ///
  // Returns the line number for the current node.
  ///
  int(CEF_CALLBACK* get_line_number)(struct _cef_xml_reader_t* self);

  // Attribute nodes are not traversed by default. The below functions can be
  // used to move the cursor to an attribute node. move_to_carrying_element()
  // can be called afterwards to return the cursor to the carrying element. The
  // depth of an attribute node will be 1 + the depth of the carrying element.

  ///
  // Moves the cursor to the attribute at the specified 0-based index. Returns
  // true (1) if the cursor position was set successfully.
  ///
  int(CEF_CALLBACK* move_to_attribute_byindex)(struct _cef_xml_reader_t* self,
                                               int index);

  ///
  // Moves the cursor to the attribute with the specified qualified name.
  // Returns true (1) if the cursor position was set successfully.
  ///
  int(CEF_CALLBACK* move_to_attribute_byqname)(
      struct _cef_xml_reader_t* self,
      const cef_string_t* qualifiedName);

  ///
  // Moves the cursor to the attribute with the specified local name and
  // namespace URI. Returns true (1) if the cursor position was set
  // successfully.
  ///
  int(CEF_CALLBACK* move_to_attribute_bylname)(
      struct _cef_xml_reader_t* self,
      const cef_string_t* localName,
      const cef_string_t* namespaceURI);

  ///
  // Moves the cursor to the first attribute in the current element. Returns
  // true (1) if the cursor position was set successfully.
  ///
  int(CEF_CALLBACK* move_to_first_attribute)(struct _cef_xml_reader_t* self);

  ///
  // Moves the cursor to the next attribute in the current element. Returns true
  // (1) if the cursor position was set successfully.
  ///
  int(CEF_CALLBACK* move_to_next_attribute)(struct _cef_xml_reader_t* self);

  ///
  // Moves the cursor back to the carrying element. Returns true (1) if the
  // cursor position was set successfully.
  ///
  int(CEF_CALLBACK* move_to_carrying_element)(struct _cef_xml_reader_t* self);
} cef_xml_reader_t;

///
// Create a new cef_xml_reader_t object. The returned object's functions can
// only be called from the thread that created the object.
///
CEF_EXPORT cef_xml_reader_t* cef_xml_reader_create(
    struct _cef_stream_reader_t* stream,
    cef_xml_encoding_type_t encodingType,
    const cef_string_t* URI);

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_XML_READER_CAPI_H_
