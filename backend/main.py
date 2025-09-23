# @zyos73
# 23/09/2025

from fastapi import FastAPI
from pydantic import BaseModel
from datetime import datetime

app = FastAPI()

class WaterEvent(BaseModel):
    device_id: str
    timestamp: datetime
    water_detected: bool

events = []

@app.post("/api/events")
def receive_event(event: WaterEvent):
    events.append(event)
    return {"status": "ok", "received": event}

@app.get("/api/stats")
def get_stats():
    return {
        "total_events": len(events),
        "last_event": events[-1] if events else None
    }