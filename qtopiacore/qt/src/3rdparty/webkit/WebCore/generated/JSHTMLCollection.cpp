/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#include "JSHTMLCollection.h"

#include <wtf/GetPtr.h>

#include "AtomicString.h"
#include "HTMLCollection.h"
#include "JSNode.h"
#include "JSNodeList.h"
#include "NameNodeList.h"
#include "Node.h"
#include "NodeList.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashEntry JSHTMLCollectionTableEntries[] =
{
    { 0, 0, 0, 0, 0 },
    { "length", JSHTMLCollection::LengthAttrNum, DontDelete|ReadOnly, 0, &JSHTMLCollectionTableEntries[2] },
    { "constructor", JSHTMLCollection::ConstructorAttrNum, DontDelete|DontEnum|ReadOnly, 0, 0 }
};

static const HashTable JSHTMLCollectionTable = 
{
    2, 3, JSHTMLCollectionTableEntries, 2
};

/* Hash table for constructor */

static const HashEntry JSHTMLCollectionConstructorTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLCollectionConstructorTable = 
{
    2, 1, JSHTMLCollectionConstructorTableEntries, 1
};

class JSHTMLCollectionConstructor : public DOMObject {
public:
    JSHTMLCollectionConstructor(ExecState* exec)
    {
        setPrototype(exec->lexicalInterpreter()->builtinObjectPrototype());
        putDirect(exec->propertyNames().prototype, JSHTMLCollectionPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLCollectionConstructor::info = { "HTMLCollectionConstructor", 0, &JSHTMLCollectionConstructorTable, 0 };

bool JSHTMLCollectionConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLCollectionConstructor, DOMObject>(exec, &JSHTMLCollectionConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLCollectionConstructor::getValueProperty(ExecState*, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(token);
}

/* Hash table for prototype */

static const HashEntry JSHTMLCollectionPrototypeTableEntries[] =
{
    { "namedItem", JSHTMLCollection::NamedItemFuncNum, DontDelete|Function, 1, &JSHTMLCollectionPrototypeTableEntries[3] },
    { 0, 0, 0, 0, 0 },
    { "item", JSHTMLCollection::ItemFuncNum, DontDelete|Function, 1, 0 },
    { "tags", JSHTMLCollection::TagsFuncNum, DontDelete|Function, 1, 0 }
};

static const HashTable JSHTMLCollectionPrototypeTable = 
{
    2, 4, JSHTMLCollectionPrototypeTableEntries, 3
};

const ClassInfo JSHTMLCollectionPrototype::info = { "HTMLCollectionPrototype", 0, &JSHTMLCollectionPrototypeTable, 0 };

JSObject* JSHTMLCollectionPrototype::self(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLCollectionPrototype>(exec, "[[JSHTMLCollection.prototype]]");
}

bool JSHTMLCollectionPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSHTMLCollectionPrototypeFunction, JSObject>(exec, &JSHTMLCollectionPrototypeTable, this, propertyName, slot);
}

const ClassInfo JSHTMLCollection::info = { "HTMLCollection", 0, &JSHTMLCollectionTable, 0 };

JSHTMLCollection::JSHTMLCollection(ExecState* exec, HTMLCollection* impl)
    : m_impl(impl)
{
    setPrototype(JSHTMLCollectionPrototype::self(exec));
}

JSHTMLCollection::~JSHTMLCollection()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());
}

bool JSHTMLCollection::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    JSValue* proto = prototype();
    if (proto->isObject() && static_cast<JSObject*>(proto)->hasProperty(exec, propertyName))
        return false;

    const HashEntry* entry = Lookup::findEntry(&JSHTMLCollectionTable, propertyName);
    if (entry) {
        slot.setStaticEntry(this, entry, staticValueGetter<JSHTMLCollection>);
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<HTMLCollection*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    if (canGetItemsForName(exec, static_cast<HTMLCollection*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    return KJS::DOMObject::getOwnPropertySlot(exec, propertyName, slot);
}

JSValue* JSHTMLCollection::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case LengthAttrNum: {
        HTMLCollection* imp = static_cast<HTMLCollection*>(impl());

        return jsNumber(imp->length());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

JSValue* JSHTMLCollection::getConstructor(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLCollectionConstructor>(exec, "[[HTMLCollection.constructor]]");
}
JSValue* JSHTMLCollectionPrototypeFunction::callAsFunction(ExecState* exec, JSObject* thisObj, const List& args)
{
    if (!thisObj->inherits(&JSHTMLCollection::info))
      return throwError(exec, TypeError);

    HTMLCollection* imp = static_cast<HTMLCollection*>(static_cast<JSHTMLCollection*>(thisObj)->impl());

    switch (id) {
    case JSHTMLCollection::ItemFuncNum: {
        return static_cast<JSHTMLCollection*>(thisObj)->item(exec, args);
    }
    case JSHTMLCollection::NamedItemFuncNum: {
        return static_cast<JSHTMLCollection*>(thisObj)->namedItem(exec, args);
    }
    case JSHTMLCollection::TagsFuncNum: {
        String name = args[0]->toString(exec);


        KJS::JSValue* result = toJS(exec, WTF::getPtr(imp->tags(name)));
        return result;
    }
    }
    return 0;
}

JSValue* JSHTMLCollection::indexGetter(ExecState* exec, JSObject* originalObject, const Identifier& propertyName, const PropertySlot& slot)
{
    JSHTMLCollection* thisObj = static_cast<JSHTMLCollection*>(slot.slotBase());
    return toJS(exec, static_cast<HTMLCollection*>(thisObj->impl())->item(slot.index()));
}
HTMLCollection* toHTMLCollection(KJS::JSValue* val)
{
    return val->isObject(&JSHTMLCollection::info) ? static_cast<JSHTMLCollection*>(val)->impl() : 0;
}

}