#include <iostream>
#include <Python.h>
# include <numpy/arrayobject.h>

using namespace std;

// wrapper function
void great_function_from_python(char** imgArr) {

	int res; 
	PyObject *pModule,*pFunc; 
	PyObject *pArgs, *pValue; 
	
	/* import */ 
	pModule = PyImport_Import(PyString_FromString("great_module")); 
	
	/* great_module.great_function */
	pFunc = PyObject_GetAttrString(pModule, "great_function"); 
	
	/* build args */ 
	pArgs = PyTuple_New(5); 
	PyTuple_SetItem(pArgs,0, PyString_FromString(imgArr[0])); 
	PyTuple_SetItem(pArgs,1, PyString_FromString(imgArr[1])); 
	PyTuple_SetItem(pArgs,2, PyString_FromString(imgArr[2]));
	PyTuple_SetItem(pArgs,3, PyString_FromString(imgArr[3]));
	PyTuple_SetItem(pArgs,4, PyString_FromString(imgArr[4]));
	
	/* call */ 
	pValue = PyObject_CallObject(pFunc, pArgs); 
	res = PyInt_AsLong(pValue);
	printf("result = %d \n", res);
	
	
//	import_array();
//	// Convert it to a NumPy array.
//	npy_intp dims[1];
//	PyObject *pArray = PyArray_SimpleNewFromData(
//		1, dims, NPY_STRING, reinterpret_cast<string*>imgArr);
//
//	if (pArray)
//	{
//		//PyArrayObject *np_arr = reinterpret_cast<PyArrayObject*>(pArray);
//		
//		//		PyObject *pReturn = PyObject_CallFunctionObjArgs(pFunc, pArray, NULL);
//		//		res = PyInt_AsLong(pValue);
//		//		printf(" the return value = %d", res);
//		
//		pArgs = PyTuple_New (1);
//		PyTuple_SetItem (pArgs, 0, pArray);
//		pValue = PyObject_CallObject(pFunc, pArgs); 
//		if (PyCallable_Check (pFunc)) 
//		{
//			PyObject_CallObject (pFunc, pArgs);
//		} else 
//		{
//			printf ("Function not callable !\n");
//		}
//
//	}
//	else {
//		printf ("failed !\n");
//	}
//			

	Py_DECREF(pFunc);
	Py_DECREF(pModule);
	Py_DECREF(pArgs);
	Py_DECREF(pValue);
	
	return; 
}
int main()
{
	string image_1 = "111";
	string image_2 = "222";
	string image_3 = "333";
	string image_4 = "444";
	string image_5 = "555";
	
	char* image_array[5];
	image_array[0] = (char*)image_1.c_str();
	image_array[1] = (char*)image_2.c_str();
	image_array[2] = (char*)image_3.c_str();
	image_array[3] = (char*)image_4.c_str();
	image_array[4] = (char*)image_5.c_str();
	
//	string image_array[5];
//	image_array[0] =  "111";
//	image_array[1] = "222";
//	image_array[2] = "333";
//	image_array[3] = "444";
//	image_array[4] = "555";
	
    Py_Initialize();
	
    great_function_from_python(image_array);

    Py_Finalize();


    return 0;
}
