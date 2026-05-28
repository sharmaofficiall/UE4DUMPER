#ifndef SDK_H
#define SDK_H

#include "StructsSDK.h"
#include "FNames.h"
#include "GUObjects.h"

using namespace std;

string resolveProp(list<kaddr> &recurrce, kaddr prop) {
    if (prop) {
        string cname = UObject::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty")
            || isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty")
            || isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);
            recurrce.push_back(propertyClass);
            return UObject::getName(propertyClass) + "*";
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);
            recurrce.push_back(metaClass);
            return "class " + UObject::getName(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);
            recurrce.push_back(interfaceClass);
            return "interface class" + UObject::getName(interfaceClass);
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);
            recurrce.push_back(Struct);
            return UObject::getName(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            return resolveProp(recurrce, UArrayProperty::getInner(prop)) + "[]";
        } else if (isEqual(cname, "SetProperty")) {
            return "<" + resolveProp(recurrce, USetProperty::getElementProp(prop)) + ">";
        } else if (isEqual(cname, "MapProperty")) {
            return "<" + resolveProp(recurrce, UMapProperty::getKeyProp(prop)) + "," +
                   resolveProp(recurrce, UMapProperty::getValueProp(prop)) + ">";
        } else if (isEqual(cname, "BoolProperty")) {
            return "bool";
        } else if (isEqual(cname, "ByteProperty")) {
            return "byte";
        } else if (isEqual(cname, "IntProperty")) {
            return "int";
        } else if (isEqual(cname, "Int8Property")) {
            return "int8";
        } else if (isEqual(cname, "Int16Property")) {
            return "int16";
        } else if (isEqual(cname, "Int64Property")) {
            return "int64";
        } else if (isEqual(cname, "UInt16Property")) {
            return "uint16";
        } else if (isEqual(cname, "UInt32Property")) {
            return "uint32";
        } else if (isEqual(cname, "UInt64Property")) {
            return "uint64";
        } else if (isEqual(cname, "DoubleProperty")) {
            return "double";
        } else if (isEqual(cname, "FloatProperty")) {
            return "float";
        } else if (isEqual(cname, "EnumProperty")) {
            return "enum";
        } else if (isEqual(cname, "StrProperty")) {
            return "FString";
        } else if (isEqual(cname, "TextProperty")) {
            return "FText";
        } else if (isEqual(cname, "NameProperty")) {
            return "FName";
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty")) {
            return "delegate";
        } else {
            return UObject::getName(prop) + "(" + cname + ")";
        }
    }
    return "NULL";
}

string resolveProp423(list<kaddr> &recurrce, kaddr prop) {
    if (prop) {
        string cname = FField::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty")
            || isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty")
            || isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);
            recurrce.push_back(propertyClass);
            return UObject::getName(propertyClass) + "*";
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);
            recurrce.push_back(metaClass);
            return "class " + UObject::getName(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);
            recurrce.push_back(interfaceClass);
            return "interface class" + UObject::getName(interfaceClass);
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);
            recurrce.push_back(Struct);
            return UObject::getName(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            return resolveProp423(recurrce, UArrayProperty::getInner(prop)) + "[]";
        } else if (isEqual(cname, "SetProperty")) {
            return "<" + resolveProp423(recurrce, USetProperty::getElementProp(prop)) + ">";
        } else if (isEqual(cname, "MapProperty")) {
            return "<" + resolveProp423(recurrce, UMapProperty::getKeyProp(prop)) + "," +
                   resolveProp423(recurrce, UMapProperty::getValueProp(prop)) + ">";
        } else if (isEqual(cname, "BoolProperty")) {
            return "bool";
        } else if (isEqual(cname, "ByteProperty")) {
            return "byte";
        } else if (isEqual(cname, "IntProperty")) {
            return "int";
        } else if (isEqual(cname, "Int8Property")) {
            return "int8";
        } else if (isEqual(cname, "Int16Property")) {
            return "int16";
        } else if (isEqual(cname, "Int64Property")) {
            return "int64";
        } else if (isEqual(cname, "UInt16Property")) {
            return "uint16";
        } else if (isEqual(cname, "UInt32Property")) {
            return "uint32";
        } else if (isEqual(cname, "UInt64Property")) {
            return "uint64";
        } else if (isEqual(cname, "DoubleProperty")) {
            return "double";
        } else if (isEqual(cname, "FloatProperty")) {
            return "float";
        } else if (isEqual(cname, "EnumProperty")) {
            return "enum";
        } else if (isEqual(cname, "StrProperty")) {
            return "FString";
        } else if (isEqual(cname, "TextProperty")) {
            return "FText";
        } else if (isEqual(cname, "NameProperty")) {
            return "FName";
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty")) {
            return "delegate";
        } else {
            return FField::getName(prop) + "(" + cname + ")";
        }
    }
    return "NULL";
}

//---------------------------------------------------------------------------------------------------------------------------//

uint32 classCount = 0;

vector<uint32> structIDMap;

bool isScanned(uint32 id) {
    for (unsigned int i : structIDMap) {
        if (i == id) { return true; }
    }
    return false;
}

list<kaddr> writeStructChild(ofstream &sdk, kaddr childprop) {
    list<kaddr> recurrce;
    kaddr child = childprop;
    while (child) {
        kaddr prop = child;
        string oname = UObject::getName(prop);
        string cname = UObject::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty") ||
            isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty") ||
            isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);

            sdk << "\t" << UObject::getName(propertyClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(propertyClass);
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);

            sdk << "\tclass " << UObject::getName(metaClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);

            sdk << "\tinterface class " << UObject::getName(interfaceClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);

            sdk << "\t" << UObject::getName(Struct) << " " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            sdk << "\t" << resolveProp(recurrce, UArrayProperty::getInner(prop)) << "[] " << oname
                << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "SetProperty")) {
            sdk << "\t<" << resolveProp(recurrce, USetProperty::getElementProp(prop)) << "> "
                << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "MapProperty")) {
            sdk << "\t<" << resolveProp(recurrce, UMapProperty::getKeyProp(prop)) << ","
                << resolveProp(recurrce, UMapProperty::getValueProp(prop)) << "> " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "BoolProperty")) {
            sdk << "\tbool " << oname << ";"
                << setbase(10) << "//(ByteOffset: " << (int) UBoolProperty::getByteOffset(prop)
                << ", ByteMask: " << (int) UBoolProperty::getByteMask(prop)
                << ", FieldMask: " << (int) UBoolProperty::getFieldMask(prop) << ")"
                << "[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "ByteProperty")) {
            sdk << "\tbyte " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "IntProperty")) {
            sdk << "\tint " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int8Property")) {
            sdk << "\tint8 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int16Property")) {
            sdk << "\tint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int64Property")) {
            sdk << "\tint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt16Property")) {
            sdk << "\tuint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt32Property")) {
            sdk << "\tuint32 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt64Property")) {
            sdk << "\tuint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DoubleProperty")) {
            sdk << "\tdouble " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "FloatProperty")) {
            sdk << "\tfloat " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "EnumProperty")) {
            sdk << "\tenum " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StrProperty")) {
            sdk << "\tFString " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "TextProperty")) {
            sdk << "\tFText " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "NameProperty")) {
            sdk << "\tFName " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty") ||
                   isEqual(cname, "MulticastInlineDelegateProperty") ||
                   isEqual(cname, "MulticastSparseDelegateProperty")) {
            sdk << "\tdelegate " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "XigPtrProperty")) {
            sdk << "\tXigPtrProperty " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isStartWith(cname, "Function") || isEqual(cname, "DelegateFunction")) {
            string returnVal = "void";
            string params;

            kaddr funcParam = UStruct::getChildren(prop);
            while (funcParam) {
                uint64 PropertyFlags = UProperty::getPropertyFlags(funcParam);

                if ((PropertyFlags & 0x0000000000000400) == 0x0000000000000400) {
                    returnVal = resolveProp(recurrce, funcParam);
                } else {
                    if ((PropertyFlags & 0x0000000000000100) == 0x0000000000000100) {
                        params += "out ";
                    }
                    /*if((PropertyFlags & 0x0000000008000000) == 0x0000000008000000){
                        params += "ref ";
                    }*/
                    if ((PropertyFlags & 0x0000000000000002) == 0x0000000000000002) {
                        params += "const ";
                    }
                    params += resolveProp(recurrce, funcParam);
                    params += " ";
                    params += UObject::getName(funcParam);
                    params += ", ";
                }

                funcParam = UField::getNext(funcParam);
            }

            if (!params.empty()) {
                params.pop_back();
                params.pop_back();
            }

            sdk << "\t";

            int32 FunctionFlags = UFunction::getFunctionFlags(prop);

            if ((FunctionFlags & 0x00002000) == 0x00002000) {
                sdk << "static" << " ";
            }
            /*if((FunctionFlags & 0x00000001) == 0x00000001){
                sdk << "final" << " ";
            }
            if((FunctionFlags & 0x00020000) == 0x00020000){
                sdk << "public" << " ";
            }
            if((FunctionFlags & 0x00040000) == 0x00040000){
                sdk << "private" << " ";
            }
            if((FunctionFlags & 0x00080000) == 0x00080000){
                sdk << "protected" << " ";
            }*/

            sdk << returnVal << " " << oname << "(" << params << ");"
                << "// 0x" << setbase(16) << (UFunction::getFunc(prop) - libbase) << endl;
        } else {
            sdk << "\t" << cname << " " << oname << ";"
                << "//[Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        }

        child = UField::getNext(child);
    }
    return recurrce;
}

list<kaddr> writeStructChild423(ofstream &sdk, kaddr childprop) {
    list<kaddr> recurrce;
    kaddr child = childprop;
    while (child) {
        kaddr prop = child;
        string oname = FField::getName(prop);
        string cname = FField::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty") ||
            isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty") ||
            isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);

            sdk << "\t" << UObject::getName(propertyClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(propertyClass);
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);

            sdk << "\tclass " << UObject::getName(metaClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);

            sdk << "\tinterface class " << UObject::getName(interfaceClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);

            sdk << "\t" << UObject::getName(Struct) << " " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            sdk << "\t" << resolveProp423(recurrce, UArrayProperty::getInner(prop)) << "[] "
                << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "SetProperty")) {
            sdk << "\t<" << resolveProp423(recurrce, USetProperty::getElementProp(prop)) << "> "
                << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "MapProperty")) {
            sdk << "\t<" << resolveProp423(recurrce, UMapProperty::getKeyProp(prop)) << ","
                << resolveProp423(recurrce, UMapProperty::getValueProp(prop)) << "> " << oname
                << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "BoolProperty")) {
            sdk << "\tbool " << oname << ";"
                << setbase(10) << "//(ByteOffset: " << (int) UBoolProperty::getByteOffset(prop)
                << ", ByteMask: " << (int) UBoolProperty::getByteMask(prop)
                << ", FieldMask: " << (int) UBoolProperty::getFieldMask(prop) << ")"
                << "[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "ByteProperty")) {
            sdk << "\tbyte " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "IntProperty")) {
            sdk << "\tint " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int8Property")) {
            sdk << "\tint8 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int16Property")) {
            sdk << "\tint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int64Property")) {
            sdk << "\tint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt16Property")) {
            sdk << "\tuint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt32Property")) {
            sdk << "\tuint32 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt64Property")) {
            sdk << "\tuint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DoubleProperty")) {
            sdk << "\tdouble " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "FloatProperty")) {
            sdk << "\tfloat " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "EnumProperty")) {
            sdk << "\tenum " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StrProperty")) {
            sdk << "\tFString " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "TextProperty")) {
            sdk << "\tFText " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "NameProperty")) {
            sdk << "\tFName " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty") ||
                   isEqual(cname, "MulticastInlineDelegateProperty") ||
                   isEqual(cname, "MulticastSparseDelegateProperty")) {
            sdk << "\tdelegate " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "XigPtrProperty")) {
            sdk << "\tXigPtrProperty " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else {
            sdk << "\t" << cname << " " << oname << ";"
                << "//[Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        }

        child = FField::getNext(child);
    }
    return recurrce;
}

list<kaddr> writeStructChild423_Func(ofstream &sdk, kaddr childprop) {
    list<kaddr> recurrce;
    kaddr child = childprop;
    while (child) {
        kaddr prop = child;
        string oname = UObject::getName(prop);
        string cname = UObject::getClassName(prop);

        if (isStartWith(cname, "Function") || isEqual(cname, "DelegateFunction")) {
            string returnVal = "void";
            string params;

            kaddr funcParam = UStruct::getChildProperties(prop);
            while (funcParam) {
                uint64 PropertyFlags = UProperty::getPropertyFlags(funcParam);

                if ((PropertyFlags & 0x0000000000000400) == 0x0000000000000400) {
                    returnVal = resolveProp423(recurrce, funcParam);
                } else {
                    if ((PropertyFlags & 0x0000000000000100) == 0x0000000000000100) {
                        params += "out ";
                    }
                    /*if((PropertyFlags & 0x0000000008000000) == 0x0000000008000000){
                        params += "ref ";
                    }*/
                    if ((PropertyFlags & 0x0000000000000002) == 0x0000000000000002) {
                        params += "const ";
                    }
                    params += resolveProp423(recurrce, funcParam);
                    params += " ";
                    params += FField::getName(funcParam);
                    params += ", ";
                }

                funcParam = FField::getNext(funcParam);
            }

            if (!params.empty()) {
                params.pop_back();
                params.pop_back();
            }

            sdk << "\t";

            int32 FunctionFlags = UFunction::getFunctionFlags(prop);

            if ((FunctionFlags & 0x00002000) == 0x00002000) {
                sdk << "static" << " ";
            }
            /*if((FunctionFlags & 0x00000001) == 0x00000001){
                sdk << "final" << " ";
            }
            if((FunctionFlags & 0x00020000) == 0x00020000){
                sdk << "public" << " ";
            }
            if((FunctionFlags & 0x00040000) == 0x00040000){
                sdk << "private" << " ";
            }
            if((FunctionFlags & 0x00080000) == 0x00080000){
                sdk << "protected" << " ";
            }*/

            sdk << returnVal << " " << oname << "(" << params << ");"
                << "// 0x" << setbase(16) << (UFunction::getFunc(prop) - libbase) << endl;
        } else {
            sdk << "\t" << cname << " " << oname << ";"
                << "//[Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        }

        child = UField::getNext(child);
    }
    return recurrce;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

void writeStruct(ofstream &sdk, kaddr clazz) {
    list<kaddr> recurrce;

    kaddr currStruct = clazz;
    while (UObject::isValid(currStruct)) {
        string name = UObject::getName(currStruct);
        if (isStartWith(name, "None") || isContain(name, "/Game/") || isContain(name, "_png") || name.empty()) {
            break;
        }

        uint32 NameID = UObject::getNameID(currStruct);
        if (!isScanned(NameID)) {
            //Verbose Output
            if (isVerbose) {
                cout << "Obj: 0x" << std::hex << currStruct << std::dec << endl;
                cout << "Name: " << name << endl;
                cout << "NameID: 0x" << std::hex << NameID << std::dec << endl;
                cout << "Class: " << UStruct::getStructClassPath(currStruct) << endl;
                cout << endl;
            }

            //Dumping
            structIDMap.push_back(NameID);
            sdk << "Class: " << UStruct::getStructClassPath(currStruct) << endl;
            if (isUE423) {
                recurrce.merge(writeStructChild423(sdk, UStruct::getChildProperties(currStruct)));
                recurrce.merge(writeStructChild423_Func(sdk, UStruct::getChildren(currStruct)));
            } else {
                recurrce.merge(writeStructChild(sdk, UStruct::getChildren(currStruct)));
            }
            sdk << "\n--------------------------------" << endl;
            classCount++;
        }

        currStruct = UStruct::getSuperClass(currStruct);
    }

    for (auto it = recurrce.begin(); it != recurrce.end(); ++it)
        writeStruct(sdk, *it);
}

void DumpSDK(const string& out) {
    ofstream sdk(out + "/SDK.txt", ofstream::out);
    if (sdk.is_open()) {
        cout << "Dumping SDK List" << endl;
        clock_t begin = clock();
        int32 oCount = GetObjectCount();
        kaddr guobj = getRealOffset(Offsets::GUObjectArray);
        if (deRefGUObjectArray) {
            guobj = getPtr(guobj);
        }
        cout << "GUObjectArray: " << setbase(16) << guobj << endl;
        cout << "Objects Counts: " << setbase(10) << oCount << endl;
        if(oCount < 10 || oCount > 999999){
            oCount = 300000;
        }
        for (int32 i = 0; i < oCount; i++) {
            kaddr uobj = GetUObjectFromID(i);
            if (UObject::isValid(uobj)) {
                writeStruct(sdk, UObject::getClass(uobj));
            }
        }
        sdk.close();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << setbase(10) << classCount << " Items Dumped in SDK in " << elapsed_secs << "S" << endl;
    }
}

void TestDump(kaddr uobj);

static kaddr ReadPtrSafe(kaddr address) {
    return Read<kaddr>(address, 0);
}

static int ReadIntSafe(kaddr address, int def = -1) {
    return Read<int>(address, def);
}

static bool LooksAddress(kaddr address) {
#if defined(__LP64__)
    return address > 0x10000 && address < 0x0000008000000000;
#else
    return address > 0x10000 && address < 0xFFFF0000;
#endif
}

struct GWorldLayout {
    kaddr World = 0;
    kaddr Level = 0;
    kaddr ActorList = 0;
    int ActorCount = 0;
    int ValidActorSamples = 0;
    kaddr WorldToLevel = 0;
    kaddr LevelToActors = 0;
    const char *Source = "";
};

static bool IsReasonableCount(int count) {
    return count > 0 && count < 300000;
}

static int CountValidActorSamples(kaddr actorList, int actorsCount) {
    if (!LooksAddress(actorList) || actorsCount <= 0) {
        return 0;
    }

    int valid = 0;
    int maxSamples = actorsCount < 32 ? actorsCount : 32;
    for (int i = 0; i < maxSamples; i++) {
        kaddr actor = ReadPtrSafe(actorList + (i * Offsets::PointerSize));
        if (UObject::isValid(actor) &&
            !UObject::getName(actor).empty() &&
            !UObject::getClassName(actor).empty()) {
            valid++;
        }
    }
    return valid;
}

static bool TryFindWorldLayout(kaddr world, const char *source, GWorldLayout *out) {
    if (!LooksAddress(world) || !UObject::isValid(world)) {
        return false;
    }

    GWorldLayout best{};

    for (kaddr worldOff = 0x0; worldOff <= 0x140; worldOff += 0x4) {
        kaddr level = ReadPtrSafe(world + worldOff);
        if (!LooksAddress(level)) {
            continue;
        }

        for (kaddr actorsOff = 0x0; actorsOff <= 0x300; actorsOff += 0x4) {
            kaddr actorList = ReadPtrSafe(level + actorsOff);
            int actorsCount = ReadIntSafe(level + actorsOff + 0x4);
            if (!LooksAddress(actorList) || !IsReasonableCount(actorsCount)) {
                continue;
            }

            int validSamples = CountValidActorSamples(actorList, actorsCount);
            if (validSamples <= 0) {
                continue;
            }

            if (validSamples > best.ValidActorSamples) {
                best.World = world;
                best.Level = level;
                best.ActorList = actorList;
                best.ActorCount = actorsCount;
                best.ValidActorSamples = validSamples;
                best.WorldToLevel = worldOff;
                best.LevelToActors = actorsOff;
                best.Source = source;
            }
        }
    }

    if (best.ValidActorSamples <= 0) {
        return false;
    }

    *out = best;
    return true;
}

static void LogGWorldCandidate(const char *label, kaddr world) {
    kaddr level = LooksAddress(world) ? ReadPtrSafe(world + Offsets::UWorldToPersistentLevel) : 0;
    kaddr actorList = LooksAddress(level) ? ReadPtrSafe(level + Offsets::ULevelToAActors) : 0;
    int actorsCount = LooksAddress(level) ? Read<int>(level + Offsets::ULevelToAActorsCount, -1) : -1;
    cout << "GWorld candidate " << label << ": " << setbase(16) << world
         << " | Level: " << level << " | ActorList: " << actorList
         << setbase(10) << " | ActorCount: " << actorsCount << endl;
}

static kaddr ResolveGWorldSlot() {
    if (isBGMIndia()) {
        return getRealOffset(Offsets::GWorld);
    }
    return UWorld::getGWorld();
}

static bool ResolveGWorldLayout(GWorldLayout *out) {
    kaddr slot = ResolveGWorldSlot();
    kaddr p0 = ReadPtrSafe(slot);
    kaddr p1 = ReadPtrSafe(p0);
    kaddr rawSlot = (slot > 0x3C) ? (slot - 0x3C) : slot;
    kaddr rawP0 = ReadPtrSafe(rawSlot);

    const int candidateCount = 14;
    const char *labels[candidateCount] = {
            "slot",
            "[slot]",
            "[[slot]]",
            "slot-0x3C",
            "[slot-0x3C]",
            "[slot-0x3C]+0x3C",
            "[[slot-0x3C]+0x3C]",
            "[slot+0x3C]",
            "[slot+0x7C]",
            "[slot+0x80]",
            "[[slot]+0x0]",
            "[[slot]+0x4]",
            "[[slot]+0x7C]",
            "[[slot]+0x80]",
    };
    kaddr candidates[candidateCount] = {
            slot,
            p0,
            p1,
            rawSlot,
            rawP0,
            rawP0 + 0x3C,
            ReadPtrSafe(rawP0 + 0x3C),
            ReadPtrSafe(slot + 0x3C),
            ReadPtrSafe(slot + 0x7C),
            ReadPtrSafe(slot + 0x80),
            ReadPtrSafe(p0 + 0x0),
            ReadPtrSafe(p0 + 0x4),
            ReadPtrSafe(p0 + 0x7C),
            ReadPtrSafe(p0 + 0x80),
    };

    GWorldLayout best{};
    for (int i = 0; i < candidateCount; i++) {
        if (isBGMIndia()) {
            LogGWorldCandidate(labels[i], candidates[i]);
        }

        GWorldLayout layout{};
        if (TryFindWorldLayout(candidates[i], labels[i], &layout)) {
            if (layout.ValidActorSamples > best.ValidActorSamples) {
                best = layout;
            }
        }
    }

    if (best.ValidActorSamples > 0) {
        cout << "Selected GWorld candidate: " << best.Source
             << " | WorldToLevel: 0x" << setbase(16) << best.WorldToLevel
             << " | LevelToActors: 0x" << best.LevelToActors
             << setbase(10) << " | ValidActorSamples: " << best.ValidActorSamples << endl;
        *out = best;
        return true;
    }

    out->World = p0;
    out->Level = 0;
    out->ActorList = 0;
    out->ActorCount = 0;
    out->Source = "[slot]";
    return false;
}

static void DumpSDKWithGUObjectFallback(const string& out) {
    if (Offsets::GUObjectArray < 1) {
        cout << "GWorld produced no SDK items and --guobj was not provided, cannot fallback." << endl;
        return;
    }

    cout << "GWorld produced no SDK items, falling back to GUObject SDK dump." << endl;
    DumpSDK(out);
}

void DumpSDKW(const string& out) {
    uint32 beforeCount = classCount;
    ofstream sdk(out + "/SDK.txt", ofstream::out);
    if (sdk.is_open()) {
        cout << "Dumping SDK List" << endl;
        clock_t begin = clock();
        kaddr gworldSlot = ResolveGWorldSlot();
        GWorldLayout layout{};
        bool hasLayout = ResolveGWorldLayout(&layout);
        kaddr gworld = layout.World;
        cout << "GWorldSlot: " << setbase(16) << gworldSlot << " | UWorld: " << gworld
             << setbase(10) << " | Name: " << UObject::getName(gworld) << endl;
        if (hasLayout) {
            //Iterate World
            if (UObject::isValid(gworld)) {
                writeStruct(sdk, UObject::getClass(gworld));
            }
            //Iterate Entities
            kaddr level = layout.Level;
            kaddr actorList = layout.ActorList;
            int actorsCount = layout.ActorCount;
            cout << "Level: " << setbase(16) << level << " | ActorList: " << actorList
                 << " | WorldToLevel: 0x" << layout.WorldToLevel
                 << " | LevelToActors: 0x" << layout.LevelToActors
                 << setbase(10) << " | ActorCount: " << actorsCount << endl;
            for (int i = 0; i < actorsCount; i++) {
                kaddr actor = getPtr(actorList + (i * Offsets::PointerSize));
                if (UObject::isValid(actor)) {
                    writeStruct(sdk, UObject::getClass(actor));
                }
            }
        } else {
            cout << "Invalid UWorld. Check --gworld; for BGMI use the final direct offset 0x9FEB9D0." << endl;
        }
        sdk.close();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << classCount << " Items Dumped in SDK in " << elapsed_secs << "S" << endl;
    }

    if (classCount == beforeCount) {
        DumpSDKWithGUObjectFallback(out);
    }
}

void TestDump(kaddr uobj) {
    cout << "Obj: " << setbase(16) << uobj << endl;
    cout << "Name: " << UObject::getName(uobj) << endl;
    cout << "Class: " << UObject::getName(UObject::getClass(uobj)) << endl;
    cout << "Outer: " << UObject::getName(UObject::getOuter(uobj)) << endl;
    cout << "ClassPath: " << UStruct::getClassPath(uobj) << endl;

    // HexDump(uobj, 40);printf("\n\n");

    kaddr clazz = UObject::getClass(uobj);

    // HexDump(clazz, 50);printf("\n\n");

    if (isUE423) {
        //Props
        kaddr child = UStruct::getChildProperties(clazz);
        while (child) {
            cout << setbase(16) << "0x" << child << " - " << FField::getName(child) << " - "
                 << FField::getClassName(child) << " - 0x" << UProperty::getOffset(child) << " - 0x"
                 << setbase(16) << UProperty::getArrayDim(child) << " - 0x" << UProperty::getElementSize(child) << ";" << endl;

            //HexDump(child, 40);

            child = FField::getNext(child);
        }

        //Functions
        child = UStruct::getChildren(clazz);
        while (child) {
            cout << setbase(16) << "0x" << child << " - " << UObject::getName(child) << " - "
                 << UObject::getClassName(child) <<
                 " - 0x" << UFunction::getFunc(child) - libbase << ";" << endl;

            //HexDump(child, 40);

            kaddr funcParam = UStruct::getChildProperties(child);
            while (funcParam) {
                cout << "\t" << setbase(16) << "0x" << child << " - " << FField::getName(funcParam) << " - "
                     << FField::getClassName(funcParam) << " - 0x" << UProperty::getOffset(funcParam) << " - 0x"
                     << setbase(16) << UProperty::getArrayDim(funcParam) << " - 0x" << UProperty::getElementSize(funcParam) << ";" << endl;

                funcParam = FField::getNext(funcParam);
            }

            child = UField::getNext(child);
        }
    } else {
        kaddr child = UStruct::getChildren(clazz);
        while (child) {
            cout << setbase(16) << "0x" << child << " - " << UObject::getName(child) << " - "
                 << UObject::getClassName(child) << ";" << endl;

            //HexDump(child, 30);

            child = UField::getNext(child);
        }
    }
}

void DumpActors() {
    ///Dump All Actors
    kaddr gworld = ResolveGWorldSlot();
    GWorldLayout layout{};
    bool hasLayout = ResolveGWorldLayout(&layout);
    kaddr world = layout.World;

    // kaddr vtable = getPtr(world);
    //
    // for(kaddr i = 0; i < 0x100; i++){
    //     kaddr fnAddr = getPtr(vtable + (i * Offsets::PointerSize)) - libbase;
    //     printf("VTable[0x%lx]: 0x%lx\n", i, fnAddr);
    // }

    // TestDump(world);

    cout << "UWorld: " << setbase(16) << gworld << " | World: " << world << " | Name: "
         << UObject::getName(world) << endl;

    if (!hasLayout) {
        cout << "Invalid UWorld. Check --gworld; for BGMI use the final direct offset 0x9FEB9D0." << endl;
        return;
    }

    // HexDump(world, 40, 0x0);

    kaddr level = layout.Level;
    cout << "Level: " << setbase(16) << level << " | Name: " << UObject::getName(level) << endl;

    //HexDump(level + 0x90, 60, 0x90);

    kaddr actorList = layout.ActorList;
    int actorsCount = layout.ActorCount;
    cout << "ActorList: " << setbase(16) << actorList
         << ", WorldToLevel: 0x" << layout.WorldToLevel
         << ", LevelToActors: 0x" << layout.LevelToActors
         << ", ActorCount: " << setbase(10)
         << actorsCount << "\n" << endl;

    for (int i = 0; i < actorsCount; i++) {
        kaddr actor = getPtr(actorList + (i * sizeof(kaddr)));
        if (UObject::isValid(actor)) {
            cout << "Id: " << setbase(10) << i << ", Addr: " << setbase(16) << actor << ", Actor: "
                 << UObject::getName(actor) << endl;
        } else {
            cout << "Id: " << setbase(10) << i << ", Addr: " << setbase(16) << actor << endl;
        }
    }
}

#endif
