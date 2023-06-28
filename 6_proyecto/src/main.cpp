/* Copyright 2017, Pablo Ridolfi, Juan Esteban Alarcon, Juan Manuel Cruz
 * All rights reserved.
 *
 * This file is part of Workspace.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
/** @brief This is a simple statechart example using Yakindu Statechart Tool
 * Plug-in (update site: http://updates.yakindu.org/sct/mars/releases/).
 */

/** \addtogroup statechart Simple UML Statechart example.
 ** @{ */

/*==================[inclusions]=============================================*/

#include "main.h"
#include "sapi.h"       // <= sAPI header

/* Include statechart header file. Be sure you run the statechart C code
 * generation tool!
 */

#include "ProyectoRequired.h"
#include "Proyecto.h"
#include "TimerTicks.h"
#include "DallasTemperature.h"
#include "OneWire.h"

#include "display_lcd_hd44780_gpios.h"   // Use sapi_gpio peripherals



/*==================[macros and definitions]=================================*/

#define __USE_TIME_EVENTS (true)	/* or "true" with TimerEvents */
#define TICKRATE_1MS	(1)				/* 1000 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */


/*==================[internal data declaration]==============================*/

volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Proyecto statechart;

/*! This is a timed state machine that requires timer services */
#define NOF_TIMERS (sizeof(ProyectoTimeEvents)/sizeof(sc_boolean))

TimerTicks ticks[NOF_TIMERS];

// Instancia a las clases OneWire y DallasTemperature
OneWire oneWireObjeto(GPIO4);
DallasTemperature sensorDS18B20(&oneWireObjeto);
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*! \file This header defines prototypes for all functions that are required
 *  by the state machine implementation.
 *
 *  This is a state machine uses time events which require access to a timing
 *  service. Thus the function prototypes:
 *  - proyecto_setTimer and
 *  - proyecto_unsetTimer
 *  are defined.
 *
 *  This state machine makes use of operations declared in the state machines
 *  interface or internal scopes. Thus the function prototypes:
 *  - proyectoIface_opLED
 *  are defined.
 *
 *  These functions will be called during a 'run to completion step' (runCycle)
 *  of the statechart.
 *  There are some constraints that have to be considered for the
 *  implementation of these functions:
 *  - never call the statechart API functions from within these functions.
 *  - make sure that the execution time is as short as possible.
 */

/** state machine user-defined external function (action)
 *
 * @param handle state machine instance
 * @param LEDNumber number of LED
 * @param onoff state machine operation parameter
 */

void proyectoIface_opLED(const Proyecto* handle, sc_integer LEDNumber, sc_boolean State )
{
	gpioWrite( (gpioMap_t)(LEDR + LEDNumber), State );
}

void proyectoIface_switchSalida(const  Proyecto* handle, sc_integer output, sc_boolean State )
{
	gpioWrite( (gpioMap_t)output, State );
}

sc_boolean proyectoIface_grupoStatus(const Proyecto* handle, sc_integer input){
	return gpioRead( (gpioMap_t)input );
}

void proyectoIface_displayValores(const Proyecto* handle){

	const char tempChar[8] = {
	   0b01110,
	   0b01010,
	   0b01010,
	   0b01110,
	   0b01110,
	   0b10111,
	   0b11111,
	   0b01110
	};
	char temp[7] = "Temp: ";
	uint8_t TEMP_CHAR;
	//Temperatura - Termometro
	lcdCreateChar( TEMP_CHAR, tempChar );

	char red_ext[9] = "Red Ext:";
	char grupo[8] = "Grupo:";
	char modo[6] = "Modo";
	char on[3] = "ON";
	char off[4] = "OFF";
	char grupo_falla[6] = "Falla";

	char modo_manual[7] = "Manual";
	char modo_auto[11] = "Automatico";
	char salida[9] = "Salida:";
	char salida_red[4] = "Red";
	char salida_grupo[6] = "Grupo";
	char salida_ninguna[8] = "Ninguna";

	char error[6] = "Error";

	switch(proyectoIface_get_numDisplay(&statechart)){
		case 1:
			lcdGoToXY( 0, 0 );
			lcdSendStringRaw(red_ext);
			lcdGoToXY( 9, 0 );
			if (proyectoIface_get_estadoLuz(&statechart) == 0)
				lcdSendStringRaw(on);
			else
				lcdSendStringRaw(off);

			lcdGoToXY( 0, 1 );
			lcdSendStringRaw(modo);
			lcdGoToXY( 5, 1 );

			if (proyectoIface_get_modoGrupo(&statechart) == 1)
				lcdSendStringRaw(modo_manual);
			else
				lcdSendStringRaw(modo_auto);

			delay(800);
			lcdCursorSet( LCD_CURSOR_OFF ); // Apaga el cursor
			lcdClear(); // Borrar la pantalla
			break;

		case 2:
			lcdGoToXY( 0, 0 );
			lcdSendStringRaw(grupo);
			lcdGoToXY( 8, 0 );

			if (proyectoIface_get_grupoExito(&statechart) == true)
				lcdSendStringRaw(on);
			else if (proyectoIface_get_grupoFalla(&statechart) == true)
				lcdSendStringRaw(grupo_falla);
			else
				lcdSendStringRaw(off);

			lcdGoToXY( 0, 1 );
			lcdData(TEMP_CHAR);
			lcdGoToXY( 0, 3 );
			lcdSendStringRaw(temp);
			lcdSendFloat(proyectoIface_get_temperatura(&statechart),2);
			delay(800);
			lcdCursorSet( LCD_CURSOR_OFF ); // Apaga el cursor
			lcdClear();
			break;

		case 3:
			lcdGoToXY( 0, 0 );
			lcdSendStringRaw(salida);
			lcdGoToXY( 7, 0 );

			if (proyectoIface_get_conmutacionRed(&statechart) == 1)
				lcdSendStringRaw(salida_red);
			else if (proyectoIface_get_conmutacionGrupo(&statechart) == 1)
				lcdSendStringRaw(salida_grupo);
			else
				lcdSendStringRaw(salida_ninguna);

			delay(800);
			lcdCursorSet( LCD_CURSOR_OFF ); // Apaga el cursor
			lcdClear();
			break;
		default:
			lcdGoToXY( 0, 0 );
			lcdSendStringRaw(error);
			delay(800);
			lcdCursorSet( LCD_CURSOR_OFF ); // Apaga el cursor
			lcdClear();
			break;
	}

}

void proyectoIface_guardarTemp(const Proyecto* handle){
	double temperatura;
	sensorDS18B20.requestTemperatures();
	temperatura = sensorDS18B20.getTempCByIndex(0);
	proyectoIface_set_temperatura(&statechart, temperatura);
}

/*! * This is a timed state machine that requires timer services
 */

/*! This function has to set up timers for the time events that are required
 *  by the state machine.
 */
/*! This function will be called for each time event that is relevant for a
 *  state when a state will be entered.
 *  \param evid An unique identifier of the event.
 *  \time_ms The time in milli seconds
 *  \periodic Indicates the the time event must be raised periodically until
 *   the timer is unset
 */
void proyecto_setTimer( Proyecto* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic )
{
	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

/*! This function has to unset timers for the time events that are required
 *  by the state machine.
 */
/*! This function will be called for each time event that is relevant for a
 *  state when a state will be left.
 *  \param evid An unique identifier of the event.
 */
void proyecto_unsetTimer( Proyecto* handle, const sc_eventid evid )
{
	UnsetTimerTick( ticks, NOF_TIMERS, evid );
}


/**
 * @brief	Hook on Handle interrupt from SysTick timer
 * @return	Nothing
 */
void myTickHook( void *ptr ){

	/* The sysTick Interrupt Handler only set a Flag */
	SysTick_Time_Flag = true;
}


/*! This function scan all EDU-CIAA-NXP buttons (TEC1, TEC2, TEC3 and TEC4),
 *  and return ID of pressed button (TEC1 or TEC2 or TEC3 or TEC4)
 *  or false if no button was pressed.
 */
uint32_t Buttons_GetStatus_(void) {
	uint8_t ret = false;
	uint32_t idx;

	for (idx = 0; idx < 4; ++idx) {
		if (gpioRead( (gpioMap_t)(TEC1 + idx) ) == 0)
			ret |= 1 << idx;
	}
	return ret;
}

bool_t RED_Status_(gpioMap_t pin){
	return gpioRead( pin );
}

/**
 * @brief	main routine for statechart example: EDU-CIAA-NXP - Proyecto
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t i;

	uint32_t BUTTON_Status;

	bool_t RED_Status;

	sensorDS18B20.begin();

	/* Generic Initialization */
	boardConfig();

	gpioConfig( GPIO0, GPIO_INPUT );
	gpioConfig( GPIO2, GPIO_INPUT );

	gpioConfig( GPIO1, GPIO_OUTPUT );
	gpioConfig( GPIO3, GPIO_OUTPUT );

	gpioConfig( GPIO5, GPIO_OUTPUT );
	gpioConfig( GPIO7, GPIO_OUTPUT );

	/* Init Ticks counter => TICKRATE_MS */
	tickConfig( TICKRATE_MS );

	/* Add Tick Hook */
	tickCallbackSet( myTickHook, (void*)NULL );

	/* Init Timer Ticks */
	InitTimerTicks( ticks, NOF_TIMERS );



	/* Statechart Initialization */
	proyecto_init( &statechart );
	proyecto_enter( &statechart );


	i2cInit( I2C0, 100000 );

	delay( LCD_STARTUP_WAIT_MS );   // Wait for stable power (some LCD need that)

	// Inicializar LCD de 16x2 (caracteres x lineas) con cada caracter de 5x8 pixeles
	lcdInit( 16, 2, 5, 8 );

	lcdCursorSet( LCD_CURSOR_OFF ); // Apaga el cursor
	lcdClear();                     // Borrar la pantalla

	/* LED state is toggled in the main program */
	while (1) {

		/* The uC sleeps waiting for an interruption */
		__WFI();

		/* When a interrupt wakes to the uC, the main program validates it,
		* checking the waited Flag */
		if (SysTick_Time_Flag == true) {

		/* Then reset its Flag */
			SysTick_Time_Flag = false;

		/* Then Update all Timer Ticks */
			UpdateTimers( ticks, NOF_TIMERS );

					/* Then Scan all Timer Ticks */
			for (i = 0; i < NOF_TIMERS; i++) {

				/* Then if there are pending events */
				if (IsPendEvent( ticks, NOF_TIMERS, ticks[i].evid ) == true) {

					/* Then Raise an Event -> Ticks.evid => OK */
					proyecto_raiseTimeEvent( &statechart, ticks[i].evid );

					/* Then Mark as Attached -> Ticks.evid => OK */
					MarkAsAttEvent( ticks, NOF_TIMERS, ticks[i].evid );
				}
			}


			/* Then Get status of buttons */

			BUTTON_Status = Buttons_GetStatus_();

			/* Red status */
			RED_Status = RED_Status_(GPIO0);
			/* Then if there are a pressed button */

			if (BUTTON_Status != 0){
				/* Then Raise an Event -> evTECXOprimodo => OK,
				 * and Value of pressed button -> viTecla */
				proyectoIface_raise_evTECXOprimido(&statechart, BUTTON_Status);
			}

			else{
				/* Then Run an Cycle of Statechart */
				/* Then else Raise an Event -> evTECXNoOprimido => OK */
				proyectoIface_raise_evTECXNoOprimido(&statechart);
			}


			if (RED_Status == false){
				 proyectoIface_raise_inputRedFalse(&statechart);
			}

			else{
				proyectoIface_raise_inputRedTrue(&statechart);
			}

			proyectoIface_raise_leerTemp(&statechart);

			proyectoIface_raise_showDisplay(&statechart);

			/* Then Run an Cycle of Statechart */


			proyecto_runCycle(&statechart);		// Run Cycle of Statechart


		}

	}
}


/** @} doxygen end group definition */

/*==================[end of file]============================================*/
