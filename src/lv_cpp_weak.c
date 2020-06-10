/*
 * lv_cpp_weak.c
 *
 *  Created on: 2020年4月5日
 *      Author: renshen
 */

//为一些接口函数提供默认的实现

#if 1

#include <stdint.h>

#include "lv_core/lv_obj.h"
#include "lv_core/lv_group.h"
#include "lv_misc/lv_task.h"
#include "lv_misc/lv_anim.h"

#ifndef ATTR_WEAK
#define ATTR_WEAK __attribute__((weak))
#endif

lv_obj_t * (*lv_obj_create_custom_ptr)(void*(*func)(lv_ll_t *),lv_ll_t * ll_p) = NULL;
void (*lv_obj_del_custom_ptr)(lv_obj_t * obj) = NULL;
void * (*lv_obj_allocate_ext_attr_custom_ptr) (lv_obj_t * obj, void * (*func)(void *, size_t),void * data_p, size_t new_size) = NULL;

lv_task_t * (*lv_task_create_basic_custom_ptr)(void * func,lv_ll_t * ll_p,void * n_pos) = NULL;
void (*lv_task_del_custom_ptr)(lv_task_t * task) = NULL;

lv_anim_t * (*lv_anim_create_custom_ptr)(lv_anim_t * anim, void * (*func)(lv_ll_t * ll_p), lv_ll_t * ll_p) = NULL;
void(* lv_anim_del_custom_ptr)(lv_anim_t * anim) = NULL;

lv_group_t * (*lv_group_create_custom_ptr)(void * (*func)(lv_ll_t * ll_p),lv_ll_t * ll_p) = NULL;
void (* lv_group_del_custom_ptr)(lv_group_t * group) = NULL;

lv_obj_t * ATTR_WEAK lv_obj_create_custom(void*(*func)(lv_ll_t *), lv_ll_t * ll_p)
{
	if(lv_obj_create_custom_ptr)
	{
		return lv_obj_create_custom_ptr(func,ll_p);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
		return NULL;
	}
}


void ATTR_WEAK lv_obj_del_custom(lv_obj_t * obj)
{
	if(lv_obj_del_custom_ptr)
	{
		return lv_obj_del_custom_ptr(obj);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
	}
}


void * ATTR_WEAK lv_obj_allocate_ext_attr_custom(lv_obj_t * obj, void * (*func)(void *, size_t),void * data_p, size_t new_size)
{
	if(lv_obj_allocate_ext_attr_custom_ptr)
	{
		return lv_obj_allocate_ext_attr_custom_ptr(obj,func,data_p,new_size);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
		return NULL;
	}
}


lv_task_t* ATTR_WEAK lv_task_create_basic_custom(void * func,lv_ll_t * ll_p,void * n_pos)
{
	if(lv_task_create_basic_custom_ptr)
	{
		return lv_task_create_basic_custom_ptr(func,ll_p,n_pos);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
	return NULL;
	}
}


void ATTR_WEAK lv_task_del_custom(lv_task_t * task)
{
	if(lv_task_del_custom_ptr)
	{
		lv_task_del_custom_ptr(task);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
	}
}


lv_anim_t * ATTR_WEAK lv_anim_create_custom(lv_anim_t * anim, void * (*func)(lv_ll_t * ll_p), lv_ll_t * ll_p)
{
	if(lv_anim_create_custom_ptr)
	{
		return lv_anim_create_custom_ptr(anim,func,ll_p);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
		return NULL;
	}
}

void ATTR_WEAK lv_anim_del_custom(lv_anim_t * anim)
{
	if(lv_anim_del_custom_ptr)
	{
		lv_anim_del_custom_ptr(anim);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
	}
}


lv_group_t * ATTR_WEAK lv_group_create_custom(void * (*func)(lv_ll_t * ll_p),lv_ll_t * ll_p)
{
	if(lv_group_create_custom_ptr)
	{
		return lv_group_create_custom_ptr(func,ll_p);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
		return NULL;
	}
}

void ATTR_WEAK lv_group_del_custom(lv_group_t * group)
{
	if(lv_group_del_custom_ptr)
	{
		lv_group_del_custom_ptr(group);
	}
	else
	{
		LV_LOG_ERROR(  "Error: Use default interface for lvgl_cpp");
	}
}
#endif
