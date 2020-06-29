from django.urls import path
from . import views


urlpatterns = [
    path('on', views.on),
    path('', views.blink, name='my-blink'),
    # path('/images/', views.blink.images, name='my-img'),
]