/**********************************************************************************************************
Copyright  2012   The Regents of the University of California
All Rights Reserved
 
Permission to copy, modify and distribute any part of this ORION3.0 software distribution for educational, 
research and non-profit purposes, without fee, and without a written agreement is hereby granted, provided 
that the above copyright notice, this paragraph and the following three paragraphs appear in all copies.
 
Those desiring to incorporate this ORION 3.0 software distribution into commercial products or use for 
commercial purposes should contact the Technology Transfer Office.

Technology Transfer Office
University of California, San Diego 
9500 Gilman Drive 
Mail Code 0910 
La Jolla, CA 92093-0910

Ph: (858) 534-5815
FAX: (858) 534-7345
E-MAIL:invent@ucsd.edu.

 
IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, 
INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS ORION 3.0 
SOFTWARE DISTRIBUTION, EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
 
THE ORION 3.0 SOFTWARE DISTRIBUTION PROVIDED HEREIN IS ON AN "AS IS" BASIS, AND THE UNIVERSITY OF 
CALIFORNIA HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  
THE UNIVERSITY OF CALIFORNIA MAKES NO REPRESENTATIONS AND EXTENDS NO WARRANTIES OF ANY KIND, EITHER 
IMPLIED OR EXPRESS, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS 
FOR A PARTICULAR PURPOSE, OR THAT THE USE OF THE ORION 3.0 SOFTWARE DISTRIBUTION WILL NOT INFRINGE ANY 
PATENT, TRADEMARK OR OTHER RIGHTS.
**********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "router.h"

/* global variables */
GLOBDEF(router_power_t, router_power);
GLOBDEF(router_info_t, router_info);
GLOBDEF(router_area_t, router_area);

int router_initialize(router_info_t *info, router_power_t *router_power, router_area_t *router_area)
{
	/* PHASE 1: set parameters */
	info->p_in = PARM(in_port);		/*in ports*/
	info->p_out = PARM(out_port);		/*out ports*/
	info->v_channel = PARM(v_channel);		/*virtual channels*/
	info->flit_width = PARM(flit_width);		/*flit width*/
	info->buf_in = PARM(in_buf_set);		/*input buffers*/
	info->buf_in=  PARM(out_buf_set);		/*ouput buffers*/
	info->model = PARM(crossbar_model);
	info->clk = PARM(FREQ_Hz);
	info->tr = PARM(tr); 

	/* crossbar */
	info->model = PARM(crossbar_model);

	/* PHASE 2: initialization */
	
	if(router_power){
		router_power_initialize(info, router_power);
		get_router_power(router_power);
	}
	else if(router_area){
		router_area_initialize(info, router_area);
		get_router_area(router_area);
	}

	return 1;
}