/***********************************************************************
 ***        THIS FILE IS GENERATED AUTOMATICALLY. DON'T EDIT!        ***
 ***********************************************************************/
/*
 * XML DRI client-side driver configuration
 * Copyright (C) 2003 Felix Kuehling
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * FELIX KUEHLING, OR ANY OTHER CONTRIBUTORS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */
/**
 * \file t_options.h
 * \brief Templates of common options
 * \author Felix Kuehling
 *
 * This file defines macros for common options that can be used to
 * construct driConfigOptions in the drivers. This file is only a
 * template containing English descriptions for options wrapped in
 * gettext(). xgettext can be used to extract translatable
 * strings. These strings can then be translated by anyone familiar
 * with GNU gettext. gen_xmlpool.py takes this template and fills in
 * all the translations. The result (options.h) is included by
 * xmlpool.h which in turn can be included by drivers.
 *
 * The macros used to describe otions in this file are defined in
 * ../xmlpool.h.
 */

/* This is needed for xgettext to extract translatable strings.
 * gen_xmlpool.py will discard this line. */
/* #include <libintl.h>
 * commented out by gen_xmlpool.py */

/*
 * predefined option sections and options with multi-lingual descriptions
 */


/**
 * \brief Debugging options
 */
#define DRI_CONF_SECTION_DEBUG \
DRI_CONF_SECTION_BEGIN \
	DRI_CONF_DESC(en,"Debugging") \
	DRI_CONF_DESC(ca,"Depuraci??") \
	DRI_CONF_DESC(de,"Fehlersuche") \
	DRI_CONF_DESC(es,"Depuraci??n") \
	DRI_CONF_DESC(nl,"Debuggen") \
	DRI_CONF_DESC(fr,"Debogage") \
	DRI_CONF_DESC(sv,"Fels??kning")

#define DRI_CONF_NO_RAST(def) \
DRI_CONF_OPT_BEGIN_B(no_rast, def) \
        DRI_CONF_DESC(en,"Disable 3D acceleration") \
        DRI_CONF_DESC(ca,"Deshabilita l'acceleraci?? 3D") \
        DRI_CONF_DESC(de,"3D-Beschleunigung abschalten") \
        DRI_CONF_DESC(es,"Deshabilitar aceleraci??n 3D") \
        DRI_CONF_DESC(nl,"3D versnelling uitschakelen") \
        DRI_CONF_DESC(fr,"D??sactiver l'acc??l??ration 3D") \
        DRI_CONF_DESC(sv,"Inaktivera 3D-accelerering") \
DRI_CONF_OPT_END

#define DRI_CONF_PERFORMANCE_BOXES(def) \
DRI_CONF_OPT_BEGIN_B(performance_boxes, def) \
        DRI_CONF_DESC(en,"Show performance boxes") \
        DRI_CONF_DESC(ca,"Mostra les caixes de rendiment") \
        DRI_CONF_DESC(de,"Zeige Performanceboxen") \
        DRI_CONF_DESC(es,"Mostrar cajas de rendimiento") \
        DRI_CONF_DESC(nl,"Laat prestatie boxjes zien") \
        DRI_CONF_DESC(fr,"Afficher les bo??tes de performance") \
        DRI_CONF_DESC(sv,"Visa prestandarutor") \
DRI_CONF_OPT_END

#define DRI_CONF_ALWAYS_FLUSH_BATCH(def) \
DRI_CONF_OPT_BEGIN_B(always_flush_batch, def) \
        DRI_CONF_DESC(en,"Enable flushing batchbuffer after each draw call") \
        DRI_CONF_DESC(ca,"Habilita el buidatge del batchbuffer despr??s de cada trucada de dibuix") \
        DRI_CONF_DESC(de,"Aktiviere sofortige Leerung des Stapelpuffers nach jedem Zeichenaufruf") \
        DRI_CONF_DESC(es,"Habilitar vaciado del batchbuffer despu??s de cada llamada de dibujo") \
        DRI_CONF_DESC(nl,"Enable flushing batchbuffer after each draw call") \
        DRI_CONF_DESC(fr,"Enable flushing batchbuffer after each draw call") \
        DRI_CONF_DESC(sv,"Enable flushing batchbuffer after each draw call") \
DRI_CONF_OPT_END

#define DRI_CONF_ALWAYS_FLUSH_CACHE(def) \
DRI_CONF_OPT_BEGIN_B(always_flush_cache, def) \
        DRI_CONF_DESC(en,"Enable flushing GPU caches with each draw call") \
        DRI_CONF_DESC(ca,"Habilita el buidatge de les mem??ries cau de GPU amb cada trucada de dibuix") \
        DRI_CONF_DESC(de,"Aktiviere sofortige Leerung der GPU-Zwischenspeicher mit jedem Zeichenaufruf") \
        DRI_CONF_DESC(es,"Habilitar vaciado de los cach??s GPU con cada llamada de dibujo") \
        DRI_CONF_DESC(nl,"Enable flushing GPU caches with each draw call") \
        DRI_CONF_DESC(fr,"Enable flushing GPU caches with each draw call") \
        DRI_CONF_DESC(sv,"Enable flushing GPU caches with each draw call") \
DRI_CONF_OPT_END

#define DRI_CONF_DISABLE_THROTTLING(def) \
DRI_CONF_OPT_BEGIN_B(disable_throttling, def) \
	DRI_CONF_DESC(en,"Disable throttling on first batch after flush") \
	DRI_CONF_DESC(ca,"Deshabilita la regulaci?? en el primer lot despr??s de buidar") \
	DRI_CONF_DESC(de,"Disable throttling on first batch after flush") \
	DRI_CONF_DESC(es,"Deshabilitar regulaci??n del primer lote despu??s de vaciar") \
	DRI_CONF_DESC(nl,"Disable throttling on first batch after flush") \
	DRI_CONF_DESC(fr,"Disable throttling on first batch after flush") \
	DRI_CONF_DESC(sv,"Disable throttling on first batch after flush") \
DRI_CONF_OPT_END

#define DRI_CONF_FORCE_GLSL_EXTENSIONS_WARN(def) \
DRI_CONF_OPT_BEGIN_B(force_glsl_extensions_warn, def) \
        DRI_CONF_DESC(en,"Force GLSL extension default behavior to 'warn'") \
        DRI_CONF_DESC(ca,"For??a que el comportament per defecte de les extensions GLSL sigui 'warn'") \
        DRI_CONF_DESC(de,"Force GLSL extension default behavior to 'warn'") \
        DRI_CONF_DESC(es,"Forzar que el comportamiento por defecto de las extensiones GLSL sea 'warn'") \
        DRI_CONF_DESC(nl,"Force GLSL extension default behavior to 'warn'") \
        DRI_CONF_DESC(fr,"Force GLSL extension default behavior to 'warn'") \
        DRI_CONF_DESC(sv,"Force GLSL extension default behavior to 'warn'") \
DRI_CONF_OPT_END

#define DRI_CONF_DISABLE_BLEND_FUNC_EXTENDED(def) \
DRI_CONF_OPT_BEGIN_B(disable_blend_func_extended, def) \
        DRI_CONF_DESC(en,"Disable dual source blending") \
        DRI_CONF_DESC(ca,"Deshabilita la barreja de font dual") \
        DRI_CONF_DESC(de,"Disable dual source blending") \
        DRI_CONF_DESC(es,"Deshabilitar mezcla de fuente dual") \
        DRI_CONF_DESC(nl,"Disable dual source blending") \
        DRI_CONF_DESC(fr,"Disable dual source blending") \
        DRI_CONF_DESC(sv,"Disable dual source blending") \
DRI_CONF_OPT_END

#define DRI_CONF_DISABLE_GLSL_LINE_CONTINUATIONS(def) \
DRI_CONF_OPT_BEGIN_B(disable_glsl_line_continuations, def) \
        DRI_CONF_DESC(en,"Disable backslash-based line continuations in GLSL source") \
        DRI_CONF_DESC(ca,"Deshabilitar les continuacions de l??nia basades en barra invertida en la font GLSL") \
        DRI_CONF_DESC(de,"Disable backslash-based line continuations in GLSL source") \
        DRI_CONF_DESC(es,"Deshabilitar continuaciones de l??nea basadas en barra inversa en el c??digo GLSL") \
        DRI_CONF_DESC(nl,"Disable backslash-based line continuations in GLSL source") \
        DRI_CONF_DESC(fr,"Disable backslash-based line continuations in GLSL source") \
        DRI_CONF_DESC(sv,"Disable backslash-based line continuations in GLSL source") \
DRI_CONF_OPT_END

#define DRI_CONF_DISABLE_SHADER_BIT_ENCODING(def) \
DRI_CONF_OPT_BEGIN_B(disable_shader_bit_encoding, def) \
        DRI_CONF_DESC(en,"Disable GL_ARB_shader_bit_encoding") \
        DRI_CONF_DESC(ca,"Deshabilita el GL_ARB_shader_bit_encoding") \
        DRI_CONF_DESC(de,"Disable GL_ARB_shader_bit_encoding") \
        DRI_CONF_DESC(es,"Deshabilitar GL_ARB_shader_bit_encoding") \
        DRI_CONF_DESC(nl,"Disable GL_ARB_shader_bit_encoding") \
        DRI_CONF_DESC(fr,"Disable GL_ARB_shader_bit_encoding") \
        DRI_CONF_DESC(sv,"Disable GL_ARB_shader_bit_encoding") \
DRI_CONF_OPT_END

#define DRI_CONF_FORCE_GLSL_VERSION(def) \
DRI_CONF_OPT_BEGIN_V(force_glsl_version, int, def, "0:999") \
        DRI_CONF_DESC(en,"Force a default GLSL version for shaders that lack an explicit #version line") \
        DRI_CONF_DESC(ca,"For??a una versi?? GLSL per defecte en els shaders als quals falta una l??nia #version expl??cita") \
        DRI_CONF_DESC(de,"Force a default GLSL version for shaders that lack an explicit #version line") \
        DRI_CONF_DESC(es,"Forzar una versi??n de GLSL por defecto en los shaders a los cuales les falta una l??nea #version expl??cita") \
        DRI_CONF_DESC(nl,"Force a default GLSL version for shaders that lack an explicit #version line") \
        DRI_CONF_DESC(fr,"Force a default GLSL version for shaders that lack an explicit #version line") \
        DRI_CONF_DESC(sv,"Force a default GLSL version for shaders that lack an explicit #version line") \
DRI_CONF_OPT_END

#define DRI_CONF_ALLOW_GLSL_EXTENSION_DIRECTIVE_MIDSHADER(def) \
DRI_CONF_OPT_BEGIN_B(allow_glsl_extension_directive_midshader, def) \
        DRI_CONF_DESC(en,"Allow GLSL #extension directives in the middle of shaders") \
        DRI_CONF_DESC(ca,"Allow GLSL #extension directives in the middle of shaders") \
        DRI_CONF_DESC(de,"Allow GLSL #extension directives in the middle of shaders") \
        DRI_CONF_DESC(es,"Allow GLSL #extension directives in the middle of shaders") \
        DRI_CONF_DESC(nl,"Allow GLSL #extension directives in the middle of shaders") \
        DRI_CONF_DESC(fr,"Allow GLSL #extension directives in the middle of shaders") \
        DRI_CONF_DESC(sv,"Allow GLSL #extension directives in the middle of shaders") \
DRI_CONF_OPT_END



/**
 * \brief Image quality-related options
 */
#define DRI_CONF_SECTION_QUALITY \
DRI_CONF_SECTION_BEGIN \
	DRI_CONF_DESC(en,"Image Quality") \
	DRI_CONF_DESC(ca,"Qualitat d'Imatge") \
	DRI_CONF_DESC(de,"Bildqualit??t") \
	DRI_CONF_DESC(es,"Calidad de imagen") \
	DRI_CONF_DESC(nl,"Beeldkwaliteit") \
	DRI_CONF_DESC(fr,"Qualit?? d'image") \
	DRI_CONF_DESC(sv,"Bildkvalitet")

#define DRI_CONF_EXCESS_MIPMAP(def) \
DRI_CONF_OPT_BEGIN_B(excess_mipmap, def) \
	DRI_CONF_DESC(en,"Enable extra mipmap level") \
DRI_CONF_OPT_END

#define DRI_CONF_TEXTURE_DEPTH_FB       0
#define DRI_CONF_TEXTURE_DEPTH_32       1
#define DRI_CONF_TEXTURE_DEPTH_16       2
#define DRI_CONF_TEXTURE_DEPTH_FORCE_16 3
#define DRI_CONF_TEXTURE_DEPTH(def) \
DRI_CONF_OPT_BEGIN_V(texture_depth,enum,def,"0:3") \
	DRI_CONF_DESC_BEGIN(en,"Texture color depth") \
                DRI_CONF_ENUM(0,"Prefer frame buffer color depth") \
                DRI_CONF_ENUM(1,"Prefer 32 bits per texel") \
                DRI_CONF_ENUM(2,"Prefer 16 bits per texel") \
                DRI_CONF_ENUM(3,"Force 16 bits per texel") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(ca,"Profunditat de color de textura") \
                DRI_CONF_ENUM(0,"Prefereix profunditat de color del framebuffer") \
                DRI_CONF_ENUM(1,"Prefereix 32 bits per texel") \
                DRI_CONF_ENUM(2,"Prefereix 16 bits per texel") \
                DRI_CONF_ENUM(3,"For??a 16 bits per texel") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(de,"Texturfarbtiefe") \
                DRI_CONF_ENUM(0,"Bevorzuge Farbtiefe des Framebuffers") \
                DRI_CONF_ENUM(1,"Bevorzuge 32 bits pro Texel") \
                DRI_CONF_ENUM(2,"Bevorzuge 16 bits pro Texel") \
                DRI_CONF_ENUM(3,"Erzwinge 16 bits pro Texel") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(es,"Profundidad de color de textura") \
                DRI_CONF_ENUM(0,"Preferir profundidad de color del framebuffer") \
                DRI_CONF_ENUM(1,"Preferir 32 bits por texel") \
                DRI_CONF_ENUM(2,"Preferir 16 bits por texel") \
                DRI_CONF_ENUM(3,"Forzar a 16 bits por texel") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(nl,"Textuurkleurendiepte") \
                DRI_CONF_ENUM(0,"Prefereer kaderbufferkleurdiepte") \
                DRI_CONF_ENUM(1,"Prefereer 32 bits per texel") \
                DRI_CONF_ENUM(2,"Prefereer 16 bits per texel") \
                DRI_CONF_ENUM(3,"Dwing 16 bits per texel af") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(fr,"Profondeur de texture") \
                DRI_CONF_ENUM(0,"Profondeur de couleur") \
                DRI_CONF_ENUM(1,"Pr??f??rer 32 bits par texel") \
                DRI_CONF_ENUM(2,"Pr??r??rer 16 bits par texel") \
                DRI_CONF_ENUM(3,"Forcer 16 bits par texel") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(sv,"F??rgdjup f??r texturer") \
                DRI_CONF_ENUM(0,"F??redra f??rgdjupet f??r framebuffer") \
                DRI_CONF_ENUM(1,"F??redra 32 bitar per texel") \
                DRI_CONF_ENUM(2,"F??redra 16 bitar per texel") \
                DRI_CONF_ENUM(3,"Tvinga 16 bitar per texel") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_DEF_MAX_ANISOTROPY(def,range) \
DRI_CONF_OPT_BEGIN_V(def_max_anisotropy,float,def,range) \
        DRI_CONF_DESC(en,"Initial maximum value for anisotropic texture filtering") \
        DRI_CONF_DESC(ca,"Valor m??xim inicial per a la filtraci?? de textura anis??tropa") \
        DRI_CONF_DESC(de,"Initialer Maximalwert f??r anisotropische Texturfilterung") \
        DRI_CONF_DESC(es,"Valor m??ximo inicial para filtrado anisotr??pico de textura") \
        DRI_CONF_DESC(nl,"Init??ele maximum waarde voor anisotrophische textuur filtering") \
        DRI_CONF_DESC(fr,"Valeur maximale initiale pour le filtrage anisotropique de texture") \
        DRI_CONF_DESC(sv,"Initialt maximalt v??rde f??r anisotropisk texturfiltrering") \
DRI_CONF_OPT_END

#define DRI_CONF_NO_NEG_LOD_BIAS(def) \
DRI_CONF_OPT_BEGIN_B(no_neg_lod_bias, def) \
        DRI_CONF_DESC(en,"Forbid negative texture LOD bias") \
        DRI_CONF_DESC(ca,"Prohibeix una parcialitat negativa del Nivell de Detalle (LOD) de les textures") \
        DRI_CONF_DESC(de,"Verbiete negative Textur-Detailgradverschiebung") \
        DRI_CONF_DESC(es,"Prohibir valores negativos de Nivel De Detalle (LOD) de texturas") \
        DRI_CONF_DESC(nl,"Verbied negatief niveau detailonderscheid (LOD) van texturen") \
        DRI_CONF_DESC(fr,"Interdire le LOD bias negatif") \
        DRI_CONF_DESC(sv,"F??rbjud negativ LOD-kompensation f??r texturer") \
DRI_CONF_OPT_END

#define DRI_CONF_FORCE_S3TC_ENABLE(def) \
DRI_CONF_OPT_BEGIN_B(force_s3tc_enable, def) \
        DRI_CONF_DESC(en,"Enable S3TC texture compression even if software support is not available") \
        DRI_CONF_DESC(ca,"Habilitar la compressi?? de textures S3TC encara que el suport de programari no estigui disponible") \
        DRI_CONF_DESC(de,"Aktiviere S3TC Texturkomprimierung auch wenn die n??tige Softwareunterst??tzung fehlt") \
        DRI_CONF_DESC(es,"Habilitar la compresi??n de texturas S3TC incluso si el soporte por software no est?? disponible") \
        DRI_CONF_DESC(nl,"Schakel S3TC textuurcompressie in, zelfs als softwareondersteuning niet aanwezig is") \
        DRI_CONF_DESC(fr,"Activer la compression de texture S3TC m??me si le support logiciel est absent") \
        DRI_CONF_DESC(sv,"Aktivera S3TC-texturkomprimering ??ven om programvarust??d saknas") \
DRI_CONF_OPT_END

#define DRI_CONF_COLOR_REDUCTION_ROUND 0
#define DRI_CONF_COLOR_REDUCTION_DITHER 1
#define DRI_CONF_COLOR_REDUCTION(def) \
DRI_CONF_OPT_BEGIN_V(color_reduction,enum,def,"0:1") \
        DRI_CONF_DESC_BEGIN(en,"Initial color reduction method") \
                DRI_CONF_ENUM(0,"Round colors") \
                DRI_CONF_ENUM(1,"Dither colors") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(ca,"M??tode inicial de reducci?? de color") \
                DRI_CONF_ENUM(0,"Colors arrodonits") \
                DRI_CONF_ENUM(1,"Colors tramats") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(de,"Initiale Farbreduktionsmethode") \
                DRI_CONF_ENUM(0,"Farben runden") \
                DRI_CONF_ENUM(1,"Farben rastern") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(es,"M??todo inicial de reducci??n de color") \
                DRI_CONF_ENUM(0,"Colores redondeados") \
                DRI_CONF_ENUM(1,"Colores suavizados") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(nl,"Init??ele kleurreductie methode") \
                DRI_CONF_ENUM(0,"Rond kleuren af") \
                DRI_CONF_ENUM(1,"Rasteriseer kleuren") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(fr,"Technique de r??duction de couleurs") \
                DRI_CONF_ENUM(0,"Arrondir les valeurs de couleur") \
                DRI_CONF_ENUM(1,"Tramer les couleurs") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(sv,"Initial f??rgminskningsmetod") \
                DRI_CONF_ENUM(0,"Avrunda f??rger") \
                DRI_CONF_ENUM(1,"Utj??mna f??rger") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_ROUND_TRUNC 0
#define DRI_CONF_ROUND_ROUND 1
#define DRI_CONF_ROUND_MODE(def) \
DRI_CONF_OPT_BEGIN_V(round_mode,enum,def,"0:1") \
	DRI_CONF_DESC_BEGIN(en,"Color rounding method") \
                DRI_CONF_ENUM(0,"Round color components downward") \
                DRI_CONF_ENUM(1,"Round to nearest color") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(ca,"M??tode d'arrodoniment de color") \
                DRI_CONF_ENUM(0,"Arrondeix els components de color a baix") \
                DRI_CONF_ENUM(1,"Arrondeix al color m??s proper") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(de,"Farbrundungsmethode") \
                DRI_CONF_ENUM(0,"Farbkomponenten abrunden") \
                DRI_CONF_ENUM(1,"Zur ??hnlichsten Farbe runden") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(es,"M??todo de redondeo de colores") \
                DRI_CONF_ENUM(0,"Redondear hacia abajo los componentes de color") \
                DRI_CONF_ENUM(1,"Redondear al color m??s cercano") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(nl,"Kleurafrondingmethode") \
                DRI_CONF_ENUM(0,"Rond kleurencomponenten af naar beneden") \
                DRI_CONF_ENUM(1,"Rond af naar dichtsbijzijnde kleur") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(fr,"M??thode d'arrondi des couleurs") \
                DRI_CONF_ENUM(0,"Arrondi ?? l'inf??rieur") \
                DRI_CONF_ENUM(1,"Arrondi au plus proche") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(sv,"F??rgavrundningsmetod") \
                DRI_CONF_ENUM(0,"Avrunda f??rdkomponenter ned??t") \
                DRI_CONF_ENUM(1,"Avrunda till n??rmsta f??rg") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_DITHER_XERRORDIFF 0
#define DRI_CONF_DITHER_XERRORDIFFRESET 1
#define DRI_CONF_DITHER_ORDERED 2
#define DRI_CONF_DITHER_MODE(def) \
DRI_CONF_OPT_BEGIN_V(dither_mode,enum,def,"0:2") \
	DRI_CONF_DESC_BEGIN(en,"Color dithering method") \
                DRI_CONF_ENUM(0,"Horizontal error diffusion") \
                DRI_CONF_ENUM(1,"Horizontal error diffusion, reset error at line start") \
                DRI_CONF_ENUM(2,"Ordered 2D color dithering") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(ca,"M??tode de tramat de color") \
                DRI_CONF_ENUM(0,"Difusi?? d'error horitzontal") \
                DRI_CONF_ENUM(1,"Difusi?? d'error horitzontal, reinicia l'error a l'inici de la l??nia") \
                DRI_CONF_ENUM(2,"Tramat de color 2D ordenat") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(de,"Farbrasterungsmethode") \
                DRI_CONF_ENUM(0,"Horizontale Fehlerstreuung") \
                DRI_CONF_ENUM(1,"Horizontale Fehlerstreuung, Fehler am Zeilenanfang zur??cksetzen") \
                DRI_CONF_ENUM(2,"Geordnete 2D Farbrasterung") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(es,"M??todo de suavizado de color") \
                DRI_CONF_ENUM(0,"Difusi??n de error horizontal") \
                DRI_CONF_ENUM(1,"Difusi??n de error horizontal, reiniciar error al comienzo de l??nea") \
                DRI_CONF_ENUM(2,"Suavizado de color 2D ordenado") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(nl,"Kleurrasteriseringsmethode") \
                DRI_CONF_ENUM(0,"Horizontale foutdiffusie") \
                DRI_CONF_ENUM(1,"Horizontale foutdiffusie, zet fout bij lijnbegin terug") \
                DRI_CONF_ENUM(2,"Geordende 2D kleurrasterisering") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(fr,"M??thode de tramage") \
                DRI_CONF_ENUM(0,"Diffusion d'erreur horizontale") \
                DRI_CONF_ENUM(1,"Diffusion d'erreur horizontale, r??initialis?? pour chaque ligne") \
                DRI_CONF_ENUM(2,"Tramage ordonn?? des couleurs") \
        DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(sv,"F??rgutj??mningsmetod") \
                DRI_CONF_ENUM(0,"Horisontell felspridning") \
                DRI_CONF_ENUM(1,"Horisontell felspridning, ??terst??ll fel vid radb??rjan") \
                DRI_CONF_ENUM(2,"Ordnad 2D-f??rgutj??mning") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_FLOAT_DEPTH(def) \
DRI_CONF_OPT_BEGIN_B(float_depth, def) \
        DRI_CONF_DESC(en,"Floating point depth buffer") \
        DRI_CONF_DESC(ca,"Buffer de profunditat de punt flotant") \
        DRI_CONF_DESC(de,"Flie??komma z-Puffer") \
        DRI_CONF_DESC(es,"B??fer de profundidad en coma flotante") \
        DRI_CONF_DESC(nl,"Dieptebuffer als commagetal") \
        DRI_CONF_DESC(fr,"Z-buffer en virgule flottante") \
        DRI_CONF_DESC(sv,"Buffert f??r flytande punktdjup") \
DRI_CONF_OPT_END

#define DRI_CONF_PP_CELSHADE(def) \
DRI_CONF_OPT_BEGIN_V(pp_celshade,enum,def,"0:1") \
        DRI_CONF_DESC(en,"A post-processing filter to cel-shade the output") \
        DRI_CONF_DESC(ca,"Un filtre de postprocessament per a aplicar cel shading a la sortida") \
        DRI_CONF_DESC(de,"Nachbearbeitungsfilter f??r Cell Shading") \
        DRI_CONF_DESC(es,"Un filtro de postprocesamiento para aplicar cel shading a la salida") \
        DRI_CONF_DESC(nl,"A post-processing filter to cel-shade the output") \
        DRI_CONF_DESC(fr,"A post-processing filter to cel-shade the output") \
        DRI_CONF_DESC(sv,"A post-processing filter to cel-shade the output") \
DRI_CONF_OPT_END

#define DRI_CONF_PP_NORED(def) \
DRI_CONF_OPT_BEGIN_V(pp_nored,enum,def,"0:1") \
        DRI_CONF_DESC(en,"A post-processing filter to remove the red channel") \
        DRI_CONF_DESC(ca,"Un filtre de postprocessament per a treure el canal vermell") \
        DRI_CONF_DESC(de,"Nachbearbeitungsfilter zum Entfernen des Rotkanals") \
        DRI_CONF_DESC(es,"Un filtro de postprocesamiento para eliminar el canal rojo") \
        DRI_CONF_DESC(nl,"A post-processing filter to remove the red channel") \
        DRI_CONF_DESC(fr,"A post-processing filter to remove the red channel") \
        DRI_CONF_DESC(sv,"A post-processing filter to remove the red channel") \
DRI_CONF_OPT_END

#define DRI_CONF_PP_NOGREEN(def) \
DRI_CONF_OPT_BEGIN_V(pp_nogreen,enum,def,"0:1") \
        DRI_CONF_DESC(en,"A post-processing filter to remove the green channel") \
        DRI_CONF_DESC(ca,"Un filtre de postprocessament per a treure el canal verd") \
        DRI_CONF_DESC(de,"Nachbearbeitungsfilter zum Entfernen des Gr??nkanals") \
        DRI_CONF_DESC(es,"Un filtro de postprocesamiento para eliminar el canal verde") \
        DRI_CONF_DESC(nl,"A post-processing filter to remove the green channel") \
        DRI_CONF_DESC(fr,"A post-processing filter to remove the green channel") \
        DRI_CONF_DESC(sv,"A post-processing filter to remove the green channel") \
DRI_CONF_OPT_END

#define DRI_CONF_PP_NOBLUE(def) \
DRI_CONF_OPT_BEGIN_V(pp_noblue,enum,def,"0:1") \
        DRI_CONF_DESC(en,"A post-processing filter to remove the blue channel") \
        DRI_CONF_DESC(ca,"Un filtre de postprocessament per a treure el canal blau") \
        DRI_CONF_DESC(de,"Nachbearbeitungsfilter zum Entfernen des Blaukanals") \
        DRI_CONF_DESC(es,"Un filtro de postprocesamiento para eliminar el canal azul") \
        DRI_CONF_DESC(nl,"A post-processing filter to remove the blue channel") \
        DRI_CONF_DESC(fr,"A post-processing filter to remove the blue channel") \
        DRI_CONF_DESC(sv,"A post-processing filter to remove the blue channel") \
DRI_CONF_OPT_END

#define DRI_CONF_PP_JIMENEZMLAA(def,min,max) \
DRI_CONF_OPT_BEGIN_V(pp_jimenezmlaa,int,def, # min ":" # max ) \
        DRI_CONF_DESC(en,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality") \
        DRI_CONF_DESC(ca,"Antiali??sing morfol??gic basat en el MLAA de Jimenez. 0 per deshabilitar, 8 per qualitat per defecte") \
        DRI_CONF_DESC(de,"Morphologische Kantengl??ttung (Anti-Aliasing) basierend auf Jimenez' MLAA. 0 f??r deaktiviert, 8 f??r Standardqualit??t") \
        DRI_CONF_DESC(es,"Antialiasing morfol??gico basado en el MLAA de Jimenez. 0 para deshabilitar, 8 para calidad por defecto") \
        DRI_CONF_DESC(nl,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality") \
        DRI_CONF_DESC(fr,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality") \
        DRI_CONF_DESC(sv,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality") \
DRI_CONF_OPT_END

#define DRI_CONF_PP_JIMENEZMLAA_COLOR(def,min,max) \
DRI_CONF_OPT_BEGIN_V(pp_jimenezmlaa_color,int,def, # min ":" # max ) \
        DRI_CONF_DESC(en,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality. Color version, usable with 2d GL apps") \
        DRI_CONF_DESC(ca,"Antiali??sing morfol??gic basat en el MLAA de Jimenez. 0 per deshabilitar, 8 per qualitat per defecte. Versi?? en color, utilitzable amb les aplicacions GL 2D") \
        DRI_CONF_DESC(de,"Morphologische Kantengl??ttung (Anti-Aliasing) basierend auf Jimenez' MLAA. 0 f??r deaktiviert, 8 f??r Standardqualit??t. Farbversion, f??r 2D-Anwendungen") \
        DRI_CONF_DESC(es,"Antialiasing morfol??gico basado en el MLAA de Jimenez. 0 para deshabilitar, 8 para calidad por defecto. Versi??n en color, usable con aplicaciones GL 2D") \
        DRI_CONF_DESC(nl,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality. Color version, usable with 2d GL apps") \
        DRI_CONF_DESC(fr,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality. Color version, usable with 2d GL apps") \
        DRI_CONF_DESC(sv,"Morphological anti-aliasing based on Jimenez\' MLAA. 0 to disable, 8 for default quality. Color version, usable with 2d GL apps") \
DRI_CONF_OPT_END



/**
 * \brief Performance-related options
 */
#define DRI_CONF_SECTION_PERFORMANCE \
DRI_CONF_SECTION_BEGIN \
        DRI_CONF_DESC(en,"Performance") \
        DRI_CONF_DESC(ca,"Rendiment") \
        DRI_CONF_DESC(de,"Leistung") \
        DRI_CONF_DESC(es,"Rendimiento") \
        DRI_CONF_DESC(nl,"Prestatie") \
        DRI_CONF_DESC(fr,"Performance") \
        DRI_CONF_DESC(sv,"Prestanda")

#define DRI_CONF_TCL_SW 0
#define DRI_CONF_TCL_PIPELINED 1
#define DRI_CONF_TCL_VTXFMT 2
#define DRI_CONF_TCL_CODEGEN 3
#define DRI_CONF_TCL_MODE(def) \
DRI_CONF_OPT_BEGIN_V(tcl_mode,enum,def,"0:3") \
        DRI_CONF_DESC_BEGIN(en,"TCL mode (Transformation, Clipping, Lighting)") \
                DRI_CONF_ENUM(0,"Use software TCL pipeline") \
                DRI_CONF_ENUM(1,"Use hardware TCL as first TCL pipeline stage") \
                DRI_CONF_ENUM(2,"Bypass the TCL pipeline") \
                DRI_CONF_ENUM(3,"Bypass the TCL pipeline with state-based machine code generated on-the-fly") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(ca,"Mode TCL (Transformaci??, Retall, Il??luminaci??)") \
                DRI_CONF_ENUM(0,"Utilitza la canonada TCL de programari") \
                DRI_CONF_ENUM(1,"Utilitza el TCL maquin??ri com la primera fase de la canonada TCL") \
                DRI_CONF_ENUM(2,"Passar per alt la canonada TCL") \
                DRI_CONF_ENUM(3,"Passar per alt la canonada TCL amb codi m??quina basat en estats, generat sobre la marxa") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(de,"TCL-Modus (Transformation, Clipping, Licht)") \
                DRI_CONF_ENUM(0,"Benutze die Software-TCL-Pipeline") \
                DRI_CONF_ENUM(1,"Benutze Hardware TCL als erste Stufe der TCL-Pipeline") \
                DRI_CONF_ENUM(2,"Umgehe die TCL-Pipeline") \
                DRI_CONF_ENUM(3,"Umgehe die TCL-Pipeline mit zur Laufzeit erzeugtem, zustandsbasiertem Maschinencode") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(es,"Modo TCL (Transformaci??n, Recorte, Iluminaci??n)") \
                DRI_CONF_ENUM(0,"Usar tuber??a TCL por software") \
                DRI_CONF_ENUM(1,"Usar TCL por hardware en la primera fase de la tuber??a TCL") \
                DRI_CONF_ENUM(2,"Pasar por alto la tuber??a TCL") \
                DRI_CONF_ENUM(3,"Pasar por alto la tuber??a TCL con c??digo m??quina basado en estados, generado al vuelo") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(nl,"TCL-modus (Transformatie, Clipping, Licht)") \
                DRI_CONF_ENUM(0,"Gebruik software TCL pijpleiding") \
                DRI_CONF_ENUM(1,"Gebruik hardware TCL as eerste TCL pijpleiding trap") \
                DRI_CONF_ENUM(2,"Omzeil de TCL pijpleiding") \
                DRI_CONF_ENUM(3,"Omzeil de TCL pijpleiding met staatgebaseerde machinecode die tijdens executie gegenereerd wordt") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(fr,"Mode de TCL (Transformation, Clipping, Eclairage)") \
                DRI_CONF_ENUM(0,"Utiliser un pipeline TCL logiciel") \
                DRI_CONF_ENUM(1,"Utiliser le TCL mat??riel pour le premier niveau de pipeline") \
                DRI_CONF_ENUM(2,"Court-circuiter le pipeline TCL") \
                DRI_CONF_ENUM(3,"Court-circuiter le pipeline TCL par une machine ?? ??tats qui g??n??re le codede TCL ?? la vol??e") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(sv,"TCL-l??ge (Transformation, Clipping, Lighting)") \
                DRI_CONF_ENUM(0,"Anv??nd programvaru-TCL-r??rledning") \
                DRI_CONF_ENUM(1,"Anv??nd maskinvaru-TCL som f??rsta TCL-r??rledningssteg") \
                DRI_CONF_ENUM(2,"Kringg?? TCL-r??rledningen") \
                DRI_CONF_ENUM(3,"Kringg?? TCL-r??rledningen med tillst??ndsbaserad maskinkod som direktgenereras") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_FTHROTTLE_BUSY 0
#define DRI_CONF_FTHROTTLE_USLEEPS 1
#define DRI_CONF_FTHROTTLE_IRQS 2
#define DRI_CONF_FTHROTTLE_MODE(def) \
DRI_CONF_OPT_BEGIN_V(fthrottle_mode,enum,def,"0:2") \
        DRI_CONF_DESC_BEGIN(en,"Method to limit rendering latency") \
                DRI_CONF_ENUM(0,"Busy waiting for the graphics hardware") \
                DRI_CONF_ENUM(1,"Sleep for brief intervals while waiting for the graphics hardware") \
                DRI_CONF_ENUM(2,"Let the graphics hardware emit a software interrupt and sleep") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(ca,"M??tode per a limitar la lat??ncia de renderitzaci??") \
                DRI_CONF_ENUM(0,"Espera activa pel maquinari de gr??fics") \
                DRI_CONF_ENUM(1,"Dormi per intervals breus mentre s'espera al maquinari de gr??fics") \
                DRI_CONF_ENUM(2,"Deixa que el maquinari de gr??fics emeti una interrupci?? de programari i dormi") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(de,"Methode zur Begrenzung der Bildverz??gerung") \
                DRI_CONF_ENUM(0,"Aktives Warten auf die Grafikhardware") \
                DRI_CONF_ENUM(1,"Kurze Schlafintervalle beim Warten auf die Grafikhardware") \
                DRI_CONF_ENUM(2,"Die Grafikhardware eine Softwareunterbrechnung erzeugen lassen und schlafen") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(es,"M??todo para limitar la latencia de renderizaci??n") \
                DRI_CONF_ENUM(0,"Esperar activamente al hardware gr??fico") \
                DRI_CONF_ENUM(1,"Dormir en intervalos cortos mientras se espera al hardware gr??fico") \
                DRI_CONF_ENUM(2,"Permitir que el hardware gr??fico emita una interrupci??n de software y duerma") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(nl,"Methode om beeldopbouwvertraging te onderdrukken") \
                DRI_CONF_ENUM(0,"Actief wachten voor de grafische hardware") \
                DRI_CONF_ENUM(1,"Slaap voor korte intervallen tijdens het wachten op de grafische hardware") \
                DRI_CONF_ENUM(2,"Laat de grafische hardware een software onderbreking uitzenden en in slaap vallen") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(fr,"M??thode d'attente de la carte graphique") \
                DRI_CONF_ENUM(0,"Attente active de la carte graphique") \
                DRI_CONF_ENUM(1,"Attente utilisant usleep()") \
                DRI_CONF_ENUM(2,"Utiliser les interruptions") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(sv,"Metod f??r att begr??nsa renderingslatens") \
                DRI_CONF_ENUM(0,"Upptagen med att v??nta p?? grafikh??rdvaran") \
                DRI_CONF_ENUM(1,"Sov i korta intervall under v??ntan p?? grafikh??rdvaran") \
                DRI_CONF_ENUM(2,"L??t grafikh??rdvaran s??nda ut ett programvaruavbrott och sov") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_VBLANK_NEVER 0
#define DRI_CONF_VBLANK_DEF_INTERVAL_0 1
#define DRI_CONF_VBLANK_DEF_INTERVAL_1 2
#define DRI_CONF_VBLANK_ALWAYS_SYNC 3
#define DRI_CONF_VBLANK_MODE(def) \
DRI_CONF_OPT_BEGIN_V(vblank_mode,enum,def,"0:3") \
        DRI_CONF_DESC_BEGIN(en,"Synchronization with vertical refresh (swap intervals)") \
                DRI_CONF_ENUM(0,"Never synchronize with vertical refresh, ignore application's choice") \
                DRI_CONF_ENUM(1,"Initial swap interval 0, obey application's choice") \
                DRI_CONF_ENUM(2,"Initial swap interval 1, obey application's choice") \
                DRI_CONF_ENUM(3,"Always synchronize with vertical refresh, application chooses the minimum swap interval") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(ca,"Sincronitzaci?? amb refresc vertical (intervals d'intercanvi)") \
                DRI_CONF_ENUM(0,"Mai sincronitzis amb el refresc vertial, ignora l'elecci?? de l'aplicaci??") \
                DRI_CONF_ENUM(1,"Interval d'intercanvi inicial 0, obeeix l'elecci?? de l'aplicaci??") \
                DRI_CONF_ENUM(2,"Interval d'intercanvi inicial 1, obeeix l'elecci?? de l'aplicaci??") \
                DRI_CONF_ENUM(3,"Sempre sincronitza amb el refresc vertical, l'aplicaci?? tria l'interval m??nim d'intercanvi") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(de,"Synchronisation mit der vertikalen Bildwiederholung") \
                DRI_CONF_ENUM(0,"Niemals mit der Bildwiederholung synchronisieren, Anweisungen der Anwendung ignorieren") \
                DRI_CONF_ENUM(1,"Initiales Bildinterval 0, Anweisungen der Anwendung gehorchen") \
                DRI_CONF_ENUM(2,"Initiales Bildinterval 1, Anweisungen der Anwendung gehorchen") \
                DRI_CONF_ENUM(3,"Immer mit der Bildwiederholung synchronisieren, Anwendung w??hlt das minimale Bildintervall") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(es,"Sincronizaci??n con el refresco vertical (intervalos de intercambio)") \
                DRI_CONF_ENUM(0,"No sincronizar nunca con el refresco vertical, ignorar la elecci??n de la aplicaci??n") \
                DRI_CONF_ENUM(1,"Intervalo de intercambio inicial 0, obedecer la elecci??n de la aplicaci??n") \
                DRI_CONF_ENUM(2,"Intervalo de intercambio inicial 1, obedecer la elecci??n de la aplicaci??n") \
                DRI_CONF_ENUM(3,"Sincronizar siempre con el refresco vertical, la aplicaci??n elige el intervalo de intercambio m??nimo") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(nl,"Synchronisatie met verticale verversing (interval omwisselen)") \
                DRI_CONF_ENUM(0,"Nooit synchroniseren met verticale verversing, negeer de keuze van de applicatie") \
                DRI_CONF_ENUM(1,"Init??eel omwisselingsinterval 0, honoreer de keuze van de applicatie") \
                DRI_CONF_ENUM(2,"Init??eel omwisselingsinterval 1, honoreer de keuze van de applicatie") \
                DRI_CONF_ENUM(3,"Synchroniseer altijd met verticale verversing, de applicatie kiest het minimum omwisselingsinterval") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(fr,"Synchronisation de l'affichage avec le balayage vertical") \
                DRI_CONF_ENUM(0,"Ne jamais synchroniser avec le balayage vertical, ignorer le choix de l'application") \
                DRI_CONF_ENUM(1,"Ne pas synchroniser avec le balayage vertical par d??faut, mais ob??ir au choix de l'application") \
                DRI_CONF_ENUM(2,"Synchroniser avec le balayage vertical par d??faut, mais ob??ir au choix de l'application") \
                DRI_CONF_ENUM(3,"Toujours synchroniser avec le balayage vertical, l'application choisit l'intervalle minimal") \
        DRI_CONF_DESC_END \
        DRI_CONF_DESC_BEGIN(sv,"Synkronisering med vertikal uppdatering (v??xlingsintervall)") \
                DRI_CONF_ENUM(0,"Synkronisera aldrig med vertikal uppdatering, ignorera programmets val") \
                DRI_CONF_ENUM(1,"Initialt v??xlingsintervall 0, f??lj programmets val") \
                DRI_CONF_ENUM(2,"Initialt v??xlingsintervall 1, f??lj programmets val") \
                DRI_CONF_ENUM(3,"Synkronisera alltid med vertikal uppdatering, programmet v??ljer den minsta v??xlingsintervallen") \
        DRI_CONF_DESC_END \
DRI_CONF_OPT_END

#define DRI_CONF_HYPERZ_DISABLED 0
#define DRI_CONF_HYPERZ_ENABLED 1
#define DRI_CONF_HYPERZ(def) \
DRI_CONF_OPT_BEGIN_B(hyperz, def) \
        DRI_CONF_DESC(en,"Use HyperZ to boost performance") \
        DRI_CONF_DESC(ca,"Utilitza el HyperZ per a augmentar el rendiment") \
        DRI_CONF_DESC(de,"HyperZ zur Leistungssteigerung verwenden") \
        DRI_CONF_DESC(es,"Usar HyperZ para potenciar rendimiento") \
        DRI_CONF_DESC(nl,"Gebruik HyperZ om de prestaties te verbeteren") \
        DRI_CONF_DESC(fr,"Utiliser le HyperZ pour am??liorer les performances") \
        DRI_CONF_DESC(sv,"Anv??nd HyperZ f??r att maximera prestandan") \
DRI_CONF_OPT_END

#define DRI_CONF_MAX_TEXTURE_UNITS(def,min,max) \
DRI_CONF_OPT_BEGIN_V(texture_units,int,def, # min ":" # max ) \
        DRI_CONF_DESC(en,"Number of texture units used") \
        DRI_CONF_DESC(ca,"Nombre d'unitats de textura utilitzades") \
        DRI_CONF_DESC(de,"Anzahl der benutzten Textureinheiten") \
        DRI_CONF_DESC(es,"N??mero de unidades de textura usadas") \
        DRI_CONF_DESC(nl,"Aantal textuureenheden in gebruik") \
        DRI_CONF_DESC(fr,"Nombre d'unit??s de texture") \
        DRI_CONF_DESC(sv,"Antal anv??nda texturenheter") \
DRI_CONF_OPT_END

#define DRI_CONF_TEXTURE_BLEND_QUALITY(def,range) \
DRI_CONF_OPT_BEGIN_V(texture_blend_quality,float,def,range) \
	DRI_CONF_DESC(en,"Texture filtering quality vs. speed, AKA ???brilinear??? texture filtering") \
	DRI_CONF_DESC(ca,"Qualitat vs. velocitat de filtraci?? de textura, ??lies filtraci?? ???brilinear??? de textura") \
	DRI_CONF_DESC(de,"Texturfilterqualit??t versus -geschwindigkeit, auch bekannt als ???brilineare??? Texturfilterung") \
	DRI_CONF_DESC(es,"Calidad de filtrado de textura vs. velocidad, alias filtrado ???brilinear??? de textura") \
	DRI_CONF_DESC(nl,"Textuurfilterkwaliteit versus -snelheid, ookwel bekend als ???brilineaire??? textuurfiltering") \
	DRI_CONF_DESC(fr,"Qualit??/performance du filtrage trilin??aire de texture (filtrage brilin??aire)") \
	DRI_CONF_DESC(sv,"Texturfiltreringskvalitet mot hastighet, ??ven kallad ???brilinear???-texturfiltrering") \
DRI_CONF_OPT_END

#define DRI_CONF_TEXTURE_HEAPS_ALL 0
#define DRI_CONF_TEXTURE_HEAPS_CARD 1
#define DRI_CONF_TEXTURE_HEAPS_GART 2
#define DRI_CONF_TEXTURE_HEAPS(def) \
DRI_CONF_OPT_BEGIN_V(texture_heaps,enum,def,"0:2") \
	DRI_CONF_DESC_BEGIN(en,"Used types of texture memory") \
		DRI_CONF_ENUM(0,"All available memory") \
		DRI_CONF_ENUM(1,"Only card memory (if available)") \
		DRI_CONF_ENUM(2,"Only GART (AGP/PCIE) memory (if available)") \
	DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(ca,"Tipus utilitzats de mem??ria de textura") \
		DRI_CONF_ENUM(0,"Tota la mem??ria disponible") \
		DRI_CONF_ENUM(1,"Nom??s mem??ria de tarjeta (si est?? disponible)") \
		DRI_CONF_ENUM(2,"Nom??s mem??ria GART (AGP/PCIE) (si est?? disponible)") \
	DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(de,"Benutzte Arten von Texturspeicher") \
		DRI_CONF_ENUM(0,"Aller verf??gbarer Speicher") \
		DRI_CONF_ENUM(1,"Nur Grafikspeicher (falls verf??gbar)") \
		DRI_CONF_ENUM(2,"Nur GART-Speicher (AGP/PCIE) (falls verf??gbar)") \
	DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(es,"Tipos de memoria de textura usados") \
		DRI_CONF_ENUM(0,"Toda la memoria disponible") \
		DRI_CONF_ENUM(1,"Solo memoria de tarjeta (si est?? disponible)") \
		DRI_CONF_ENUM(2,"Solo memoria GART (AGP/PCIE) (si est?? disponible)") \
	DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(nl,"Gebruikte soorten textuurgeheugen") \
		DRI_CONF_ENUM(0,"Al het beschikbaar geheugen") \
		DRI_CONF_ENUM(1,"Alleen geheugen op de kaart (als het aanwezig is)") \
		DRI_CONF_ENUM(2,"Alleen GART (AGP/PCIE) geheugen (als het aanwezig is)") \
	DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(fr,"Types de m??moire de texture") \
		DRI_CONF_ENUM(0,"Utiliser toute la m??moire disponible") \
		DRI_CONF_ENUM(1,"Utiliser uniquement la m??moire graphique (si disponible)") \
		DRI_CONF_ENUM(2,"Utiliser uniquement la m??moire GART (AGP/PCIE) (si disponible)") \
	DRI_CONF_DESC_END \
	DRI_CONF_DESC_BEGIN(sv,"Anv??nda typer av texturminne") \
		DRI_CONF_ENUM(0,"Allt tillg??ngligt minne") \
		DRI_CONF_ENUM(1,"Endast kortminne (om tillg??ngligt)") \
		DRI_CONF_ENUM(2,"Endast GART-minne (AGP/PCIE) (om tillg??ngligt)") \
	DRI_CONF_DESC_END \
DRI_CONF_OPT_END



/**
 * \brief Software-fallback options.  To allow using features (like
 * GL_ARB_vertex_program) on GPUs that don't otherwise support the feature.
 */
#define DRI_CONF_SECTION_SOFTWARE \
DRI_CONF_SECTION_BEGIN \
        DRI_CONF_DESC(en,"Features that are not hardware-accelerated") \
        DRI_CONF_DESC(ca,"Caracter??stiques no accelerades per maquinari") \
        DRI_CONF_DESC(de,"Funktionalit??t, die nicht hardwarebeschleunigt ist") \
        DRI_CONF_DESC(es,"Caracter??sticas no aceleradas por hardware") \
        DRI_CONF_DESC(nl,"Eigenschappen die niet hardwareversneld zijn") \
        DRI_CONF_DESC(fr,"Fonctionnalit??s ne b??n??ficiant pas d'une acc??l??ration mat??rielle") \
        DRI_CONF_DESC(sv,"Funktioner som inte ??r h??rdvaruaccelererade")

#define DRI_CONF_ARB_VERTEX_PROGRAM(def) \
DRI_CONF_OPT_BEGIN_B(arb_vertex_program, def) \
        DRI_CONF_DESC(en,"Enable extension GL_ARB_vertex_program") \
        DRI_CONF_DESC(ca,"Habilita l'extensi?? GL_ARB_vertex_program") \
        DRI_CONF_DESC(de,"Erweiterung GL_ARB_vertex_program aktivieren") \
        DRI_CONF_DESC(es,"Habilitar la extensi??n GL_ARB_vertex_program") \
        DRI_CONF_DESC(nl,"Zet uitbreiding GL_ARB_vertex_program aan") \
        DRI_CONF_DESC(fr,"Activer l'extension GL_ARB_vertex_program") \
        DRI_CONF_DESC(sv,"Aktivera till??gget GL_ARB_vertex_program") \
DRI_CONF_OPT_END



/**
 * \brief Miscellaneous configuration options
 */
#define DRI_CONF_SECTION_MISCELLANEOUS \
DRI_CONF_SECTION_BEGIN \
        DRI_CONF_DESC(en,"Miscellaneous") \
        DRI_CONF_DESC(ca,"Miscel??l??nia") \
        DRI_CONF_DESC(de,"Miscellaneous") \
        DRI_CONF_DESC(es,"Miscel??neo") \
        DRI_CONF_DESC(nl,"Miscellaneous") \
        DRI_CONF_DESC(fr,"Miscellaneous") \
        DRI_CONF_DESC(sv,"Miscellaneous")

#define DRI_CONF_ALWAYS_HAVE_DEPTH_BUFFER(def) \
DRI_CONF_OPT_BEGIN_B(always_have_depth_buffer, def) \
        DRI_CONF_DESC(en,"Create all visuals with a depth buffer") \
        DRI_CONF_DESC(ca,"Crea tots els visuals amb buffer de profunditat") \
        DRI_CONF_DESC(de,"Create all visuals with a depth buffer") \
        DRI_CONF_DESC(es,"Crear todos los visuales con buffer de profundidad") \
        DRI_CONF_DESC(nl,"Create all visuals with a depth buffer") \
        DRI_CONF_DESC(fr,"Create all visuals with a depth buffer") \
        DRI_CONF_DESC(sv,"Create all visuals with a depth buffer") \
DRI_CONF_OPT_END



/**
 * \brief Initialization configuration options
 */
#define DRI_CONF_SECTION_INITIALIZATION \
DRI_CONF_SECTION_BEGIN \
        DRI_CONF_DESC(en,"Initialization") \
        DRI_CONF_DESC(ca,"Initialization") \
        DRI_CONF_DESC(de,"Initialization") \
        DRI_CONF_DESC(es,"Initialization") \
        DRI_CONF_DESC(nl,"Initialization") \
        DRI_CONF_DESC(fr,"Initialization") \
        DRI_CONF_DESC(sv,"Initialization")

#define DRI_CONF_DEVICE_ID_PATH_TAG(def) \
DRI_CONF_OPT_BEGIN(device_id, string, def) \
        DRI_CONF_DESC(en,"Define the graphic device to use if possible") \
        DRI_CONF_DESC(ca,"Define the graphic device to use if possible") \
        DRI_CONF_DESC(de,"Define the graphic device to use if possible") \
        DRI_CONF_DESC(es,"Define the graphic device to use if possible") \
        DRI_CONF_DESC(nl,"Define the graphic device to use if possible") \
        DRI_CONF_DESC(fr,"Define the graphic device to use if possible") \
        DRI_CONF_DESC(sv,"Define the graphic device to use if possible") \
DRI_CONF_OPT_END
