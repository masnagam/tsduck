//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2019 Masayuki Nagamachi <masnagam@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Representation of an ARIB audio component descriptor
//!
//----------------------------------------------------------------------------

#if defined(TS_ARIB)

#pragma once
#include "tsAbstractDescriptor.h"
#include "tsVariable.h"

namespace ts {
    //!
    //! Representation of an ARIB audio component descriptor.
    //! @see ARIB STD-B10 v4.6-E2, 6.2.26.
    //! @ingroup descriptor
    //!
    class TSDUCKDLL ARIBAudioComponentDescriptor : public AbstractDescriptor
    {
    public:
        // Public members:
        uint8_t stream_content_ext;  //!< 4 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t stream_content;      //!< 4 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t component_type;      //!< 8 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t component_tag;       //!< 8 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t stream_type;         //!< 8 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t simulcast_group_tag; //!< 8 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        bool es_multi_lingual;       //!< 1 bit, see ARIB STD-B10 v4.6-E2, 6.2.26.
        bool main_component;         //!< 1 bit, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t quality_indicator;   //!< 2 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        uint8_t sampling_rate;       //!< 3 bits, see ARIB STD-B10 v4.6-E2, 6.2.26.
        UString language_code;       //!< 3 chars, see ARIB STD-B10 v4.6-E2, 6.2.26.
        UString language_code2;      //!< 3 chars, see ARIB STD-B10 v4.6-E2, 6.2.26.
        UString text;                //!< A string, see ARIB STD-B10 v4.6-E2, 6.2.26.

        //!
        //! Default constructor.
        //!
        ARIBAudioComponentDescriptor();

        //!
        //! Constructor from a binary descriptor
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in] bin A binary descriptor to deserialize.
        //!
        ARIBAudioComponentDescriptor(DuckContext& duck, const Descriptor& bin);

        // Inherited methods
        virtual void serialize(DuckContext&, Descriptor&) const override;
        virtual void deserialize(DuckContext&, const Descriptor&) override;
        virtual void buildXML(DuckContext&, xml::Element*) const override;
        virtual void fromXML(DuckContext&, const xml::Element*) override;
        DeclareDisplayDescriptor();
    };
}

#endif
