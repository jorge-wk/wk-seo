

<!-- for Google -->
<meta name="description" content="" />
<meta name="keywords" content="{{ og.title }}" />

<meta name="author" content="{{ og.title }}" />
<meta name="application-name" content="{{ og.title }}" />

<!-- for Facebook -->
<meta property="fb:app_id" content="{{ og.appId }}" />
<meta property="og:type" content="{{ og.type }}" />
<meta property="og:title" content="{{ og.title }}" />

<meta property="og:image" content="{{ app.request.getSchemeAndHttpHost() ~ asset('img/' ~ og.ogImage1) }}" />
<meta property="og:image" content="{{ app.request.getSchemeAndHttpHost() ~ asset('img/' ~ og.ogImage2) }}" />
<meta property="og:image" content="{{ app.request.getSchemeAndHttpHost() ~ asset('img/' ~ og.ogImage3) }}" />
<meta property="og:image" content="{{ app.request.getSchemeAndHttpHost() ~ asset('img/' ~ og.ogImage4) }}" />

{% if og.url is defined and og.url is not empty  %}
<meta property="og:url" content="{{ og.url }}" />
{% else %}
<meta property="og:url" content="{{ url('homepage') }}" />
{% endif %}
<meta property="og:description" content="Tävla med Kexchoklad om startplatser till Midnattsloppet, Bellmanstafetten, Stockholm Halvmaraton, Vemdalen fjällmaraton och Göteborgsvarvet!" />

<!-- for Twitter -->
<meta name="twitter:card" content="summary" />
<meta name="twitter:title" content="{{ og.title }}" />
<meta name="twitter:description" content="Tävla med Kexchoklad om startplatser till Midnattsloppet, Bellmanstafetten, Stockholm Halvmaraton, Vemdalen fjällmaraton och Göteborgsvarvet!" />
<meta name="twitter:image" content="{{ app.request.getSchemeAndHttpHost() ~ asset('img/' ~ og.ogImage1) }}" />
