/*
 * FastRPC -- Fast RPC library compatible with XML-RPC
 * Copyright (C) 2005-7  Seznam.cz, a.s.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Seznam.cz, a.s.
 * Radlicka 2, Praha 5, 15000, Czech Republic
 * http://www.seznam.cz, mailto:fastrpc@firma.seznam.cz
 *
 * FILE          $Id: frpcxmlunmarshaller.h,v 1.7 2011-02-25 09:21:08 volca Exp $
 *
 * DESCRIPTION
 *
 * AUTHOR
 *              Miroslav Talasek <miroslav.talasek@firma.seznam.cz>
 *
 * HISTORY
 *
 */
#ifndef FRPCFRPCXMLUNMARSHALLER_H
#define FRPCFRPCXMLUNMARSHALLER_H

#include <frpcplatform.h>

#include <frpcunmarshaller.h>
#include <frpcdatabuilder.h>
#include <frpcinternals.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <frpcerror.h>
#include <string.h>



namespace FRPC
{
/**
@author Miroslav Talasek
*/
class XmlUnMarshaller_t : public UnMarshaller_t
{
public:

    XmlUnMarshaller_t(DataBuilder_t & dataBuilder);


    virtual ~XmlUnMarshaller_t();
    void setValueType(const char *name);
    void setValueData(const char *data, unsigned int len);
    void closeEntity(const char *name);

    virtual void unMarshall(const char *data, unsigned int size, char type);
    virtual void finish();
    virtual ProtocolVersion_t getProtocolVersion();
    //friend class CallbacksInit_t;
    enum {EXC_NONE = 0,EXC_UNKNOWN, EXC_BAD_ALLOC, EXC_STREAM
         };
    char exception;
    std::string exErrMsg;
    long exErrNum;
    std::string localBuffer;
    /*! init xmlInitParser() for its thread sahttp://xmlsoft.org/threads.html */
    static void initXmlUnMarshaller_t();
    static void cleanupXmlUnMarshaller_t();
private:
    //static void initCallbacks();

    DataBuilder_t &dataBuilder;

    char internalType;
    char mainInternalType;
    long faultCode;

    char wantType;

    xmlParserCtxtPtr parser;
    xmlSAXHandler callbacks;
    ProtocolVersion_t protocolVersion;
    bool versionCheck;

    std::string faultString;
};

};

#endif
