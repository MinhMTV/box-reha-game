package com.digitaldojo.sdkinspector

import org.json.*
import java.lang.reflect.Modifier
import java.util.IdentityHashMap

/** Read only public zero-argument getters/fields. Never invoke commands or access private SDK internals. */
object SdkFields {
 fun read(value: Any?): Any = encode(value, IdentityHashMap(), 0)
 private fun encode(v: Any?, seen: IdentityHashMap<Any, Boolean>, depth: Int): Any {
  if(v==null) return JSONObject.NULL
  if(v is String || v is Boolean || v is Char) return v.toString().let { if(v is Boolean) v else it }
  if(v is Number) return if(v is Double && !v.isFinite() || v is Float && !v.isFinite()) JSONObject().put("nonFinite",v.toString()) else v
  if(v is Enum<*>) return JSONObject().put("class",v.javaClass.name).put("name",v.name).also { result ->
   // Sampling-rate enums expose actual IMU/barometer frequencies as public getters.
   for(m in v.javaClass.declaredMethods.filter { it.parameterCount==0 && Modifier.isPublic(it.modifiers) && !Modifier.isStatic(it.modifiers) && it.name.startsWith("get") }) {
    val key=m.name.drop(3).replaceFirstChar { it.lowercase() }
    try { result.put(key,encode(m.invoke(v),seen,depth+1)) } catch(e:Exception){result.put(key,JSONObject().put("serializationError",e.toString()))}
   }
  }
  if(v is Throwable) return JSONObject().put("class",v.javaClass.name).put("message",v.message).put("stack",v.stackTraceToString())
  if(depth>32 || seen.containsKey(v)) return JSONObject().put("serializationWarning",if(depth>32) "depth_limit" else "cycle").put("class",v.javaClass.name).put("representation",v.toString())
  seen[v]=true
  try {
   if(v is Iterable<*>) return JSONArray().also { a -> v.forEach { a.put(encode(it,seen,depth+1)) } }
   if(v is Map<*,*>) return JSONArray().also { a -> v.forEach { (k,x) -> a.put(JSONObject().put("key",encode(k,seen,depth+1)).put("value",encode(x,seen,depth+1))) } }
   if(v.javaClass.isArray) return JSONArray().also { a -> for(i in 0 until java.lang.reflect.Array.getLength(v)) a.put(encode(java.lang.reflect.Array.get(v,i),seen,depth+1)) }
   val result=JSONObject().put("_class",v.javaClass.name)
   val methods=v.javaClass.methods.filter { it.parameterCount==0 && !Modifier.isStatic(it.modifiers) && it.name!="getClass" && (it.name.startsWith("get") || it.name.startsWith("is")) }.sortedBy { it.name }
   val names=JSONObject()
   for(m in methods) {
    val base=m.name.substringBefore('-');val key=(if(base.startsWith("get"))base.drop(3) else base).replaceFirstChar { it.lowercase() }
    names.put(key,m.name)
    try { result.put(key,encode(m.invoke(v),seen,depth+1)) }
    catch(e:Exception) { result.put(key,JSONObject().put("serializationError",e.cause?.toString()?:e.toString())) }
   }
   for(field in v.javaClass.fields.filter { !Modifier.isStatic(it.modifiers) }) {
    try { result.put(field.name,encode(field.get(v),seen,depth+1)) } catch(e:Exception) { result.put(field.name,JSONObject().put("serializationError",e.toString())) }
   }
   result.put("_accessors",names)
   // Retains packed inline Duration/UUID and otherwise opaque representations alongside structured getters.
   result.put("_representation",v.toString())
   return result
  } finally { seen.remove(v) }
 }
 fun getter(value:Any,name:String):Any? = value.javaClass.methods.first { it.name.substringBefore('-')==name && it.parameterCount==0 }.invoke(value)
}
